#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

#include <iostream>

#include "mpi.h"

#include <cblas.h>
#include <assert.h>

using namespace std;

//创建数组默认全为1
void randMat(int rows, int cols, float *&Mat) {
    Mat = new float[rows * cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) Mat[i * cols + j] = 1.0;
}
//得到卷积移动次数也就是卷积后的尺寸
int get_steps(int kernel, int step, int len) {
    if (kernel > len) return 0;
    return (len - kernel) / step + 1;
}


//img2col算法
inline void img2col_conv_kernel(int leftAnchorX, int leftAnchorY, int rightAnchorX,
                        int rightAnchorY, const int xKernel, const int yKernel, const int xStep,
                        const int yStep, float *&img, float *&kernel, float *&conv) {

    int imgRows = rightAnchorX - leftAnchorX,
        imgCols = rightAnchorY - leftAnchorY;
    int convRows = get_steps(xKernel, xStep, imgRows);
    int convCols = get_steps(yKernel, yStep, imgCols);
    //原始图像img2col化
    float *flattenImg = new float[convRows * convCols * xKernel * yKernel];
    #pragma omp parallel for
        for (int i = leftAnchorX; i < rightAnchorX - xKernel; i += xStep) {
            for (int r = 0; r < xKernel; r++) {
                for (int j = leftAnchorY; j < rightAnchorY - yKernel; j += yStep) {
                    int pos = (i - leftAnchorX)/xStep * convCols + (j - leftAnchorY) / yStep;
                    memcpy(&flattenImg[pos * xKernel * yKernel + r * yKernel], &img[(i + r) * imgCols + j], sizeof(float) * yKernel);
                }
            }
        }
    //拉伸后卷积
    #pragma omp parallel for
        for (int i = 0; i < convRows * convCols; i++) {
            conv[i] = 0.0;
            for (int j = 0; j < xKernel * yKernel; j++) {
                conv[i] += flattenImg[i*xKernel*yKernel + j] * kernel[j];
            }
        }
    //或者使用Openblas提供的矩阵计算代码
    //cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, convRows * convCols, 1, xKernel * yKernel, 1.0, flattenImg, xKernel * yKernel, kernel, 1, 0.0, conv, 1);
    delete flattenImg;
}
//OpenMP原始算法
//leftAnchorX 行起点,rightAnchorX 行终点
//leftAnchorY 列起点,rightAnchorY 列终点
inline void naive_conv_kernel(int leftAnchorX, int leftAnchorY, int rightAnchorX,
                        int rightAnchorY, const int xKernel, const int yKernel, const int xStep,
                        const int yStep, float *&img, float *&kernel, float *&conv) {
    //计算的图像行数和列数
    int imgRows = rightAnchorX - leftAnchorX,
        imgCols = rightAnchorY - leftAnchorY;
	//卷积结果的行数和列数
    int convRows = get_steps(xKernel, xStep, imgRows);
    int convCols = get_steps(yKernel, yStep, imgCols);
	//对for使用多线程
	#pragma omp parallel for
    //遍历行
    for (int i = leftAnchorX; i < rightAnchorX - xKernel; i += xStep) {
        //遍历列
        for (int j = leftAnchorY; j < rightAnchorY - yKernel; j += yStep) {
            int pos = (i - leftAnchorX)/xStep * convCols + (j - leftAnchorY) / yStep;
            conv[pos] = 0.0;
            //遍历卷积行
            for (int r = i; r < i + xKernel; r++)
                //遍历卷积列
                for (int c = j; c < j + yKernel; c++) {
                    //卷积计算
                    conv[pos] += img[r * imgCols + c] *
                            kernel[(r - i) * yKernel + (c - j)];
                }
        }
    }
}

//卷积计算
void mpi_convolution(int m, int n, int xKernel, int yKernel, int xStep,
                     int yStep, float *&img, float *&kernel, float *&conv,
                     int rank, int worldsize, bool img2col) {
    //卷积的移动次数总步长（总计算份额）
    const int total_xsteps = get_steps(xKernel, xStep, m);
    const int total_ysteps = get_steps(yKernel, yStep, n);
    //每个进程获得的整数步长（部分计算份额）
    const int xsteps_per_proc = total_xsteps / worldsize;
    //运行到最后余下的步长（部分计算份额）
    const int last_xsteps = total_xsteps - xsteps_per_proc * (worldsize - 1);
	//实际步长（计算份额）
    int steps;
	//主进程发送数据给其他进程
    if (rank == 0) {
        MPI_Request *sendRequest = new MPI_Request[worldsize];
        MPI_Status *status = new MPI_Status[worldsize];
        for (int i = 1; i < worldsize; i++) {
            //判断处理的计算步长
            steps = (i == worldsize - 1) ? last_xsteps : xsteps_per_proc;
            //非阻塞发送计算份额给其他进程，自己保留一份
            //注意发送图像的img首地址是卷积核起点经过步长移动到的位置，长度是卷积核移动覆盖的长度
            MPI_Isend(&img[i * xsteps_per_proc * xStep * n],
                      (steps * xStep + xKernel - xStep) * n, MPI_FLOAT, i, 0,
                      MPI_COMM_WORLD, &sendRequest[i]);
        }
        //等待非阻塞进程完成
        for (int i = 1; i < worldsize; i++) {
            MPI_Wait(&sendRequest[i], &status[i]);
        }
        //释放资源
        delete sendRequest;
        delete status;
    } else {
        //接收进程
        MPI_Status status;
        steps = (rank == worldsize - 1) ? last_xsteps : xsteps_per_proc;
        img = new float[(steps * xStep + xKernel - xStep) * n];
        //阻塞接收，必须等待接收完成方可计算
        MPI_Recv(img, (steps * xStep + xKernel - xStep) * n, MPI_FLOAT, 0, 0,
                 MPI_COMM_WORLD, &status);
        //创建部分卷积结果矩阵
        conv = new float[steps * total_ysteps];
    }
    //同步进程，接收进程和发送进程准备计算
    MPI_Barrier(MPI_COMM_WORLD);
    steps = (rank == worldsize - 1) ? last_xsteps : xsteps_per_proc;
    //是否使用img2col计算
    if (img2col)
        img2col_conv_kernel(0, 0, steps * xStep + xKernel - xStep, n, xKernel, yKernel,
                    xStep, yStep, img, kernel, conv);
    else
        naive_conv_kernel(0, 0, steps * xStep + xKernel - xStep, n, xKernel, yKernel,
                    xStep, yStep, img, kernel, conv);
    //同步进程，准备传回数据
    MPI_Barrier(MPI_COMM_WORLD);
    //主进程接其他进程发过来的卷积结果数据
    if (rank == 0) {
        MPI_Status status;
        for (int i = 1; i < worldsize; i++) {
            steps = (i == worldsize - 1) ? last_xsteps : xsteps_per_proc;
            MPI_Recv(&conv[i * xsteps_per_proc * total_ysteps],
                     steps * total_ysteps, MPI_FLOAT, i, 0, MPI_COMM_WORLD,
                     &status);
        }
    } else {
        MPI_Send(conv, steps * total_ysteps, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
    }
    //同步进程，为计时准备
    MPI_Barrier(MPI_COMM_WORLD);
    return;
}

//主函数
int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " M N enabled-img2col";
        exit(-1);
    }
    //当前进程名
    int rank;
    //总进程数
    int worldSize;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    //获取矩阵的长和宽
    //头文件stdlib.h
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    //是否使用img2col加速
    int img2col = atoi(argv[3]);
	//卷积核大小
    int xKernel = 3, yKernel = 3;
    //移动步长
    int xStep = 1, yStep = 1;
	//图像数组，卷积和的结果数组
    float *Img, *Conv;
	//Linux下时间获取函数
    //头文件sys/time.h
    struct timeval start, stop;
    //主进程0创建数组
    if (rank == 0) {
        //图像数组
        randMat(m, n, Img);
        //卷积后的数组
        randMat(get_steps(xKernel, xStep, m), get_steps(yKernel, yStep, n),
                Conv);
    }
    //卷积核
    float *Kernel = new float[xKernel*yKernel];
    for (int i = 0; i < xKernel*yKernel; i++) Kernel[i] = 1.0;
    //计时开始
    gettimeofday(&start, NULL);
    //运行卷积函数
    mpi_convolution(m, n, xKernel, yKernel, xStep, yStep, Img, Kernel, Conv,
                    rank, worldSize, img2col);
	//计时结束
    gettimeofday(&stop, NULL);
	//主进程0打印结果
    if (rank == 0) {
        cout << "mpi convolution: "
             << (stop.tv_sec - start.tv_sec) * 1000.0 +
                    (stop.tv_usec - start.tv_usec) / 1000.0
             << " ms" << endl;
        for (int i = 0; i < min(10, m); i++) {
            for (int j = 0; j < min(10, n); j++)
                cout << Conv[i * n + j] << ' ';
            cout << endl;
        }
    }
    //内存回收
    delete Img;
    delete Conv;
    MPI_Finalize();
}
