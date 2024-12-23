// 结构体指针
// 二维数组 用指针表示
// 链表
// 文件操作
#include <stdio.h>
#include <stdlib.h>
// 一个商品的结构体
struct commodity
{
    char name[20];
    int quantity;
};

int main()
{
    int a[10]; // 静态地分配了10个整数的内存空间，40B
    // 结构体数组
    // 动态分配地址空间
    int n = 3;
    // printf("请输入商品的数量:");
    // scanf("%d", &n);
    // malloc函数,在程序运行的时候分配内存,在程序运行的时候 [分配内存],在stdlib.h头文件里面
    // sizeof(struct commodity) 这个结构体的大小
    // 这个数组一共要占多大的内存空间,n个商品的内存空间,n*sizeof(struct commodity)
    // malloc(n * sizeof(struct commodity)); 返回值是void * ,void *是万能指针,可以指向任何类型的数据
    struct commodity *comlist = (struct commodity *)malloc(n * sizeof(struct commodity));
    if (comlist == NULL) // 检查是否分配成功，如果等于NULL，说明分配失败，因为并没有分配内存，为空指针
    {
        printf("分配内存失败\n");
        return 1; // 结束main，直接return 1
    }
    // 做完上一步，我们就得到了一个存储n个商品的内存空间的首地址 comlist = 结构体数组的变量名 = 结构体数组的首地址 = 数组第一个元素的地址 = &comlist[0]
    // 就可以开始给这个结构体数组赋值了
    struct commodity com1 = {"apple", 10};
    comlist[0] = com1;
    struct commodity com2 = {"banana", 20};
    comlist[1] = com2;
    struct commodity com3 = {"orange", 30};
    comlist[2] = com3;
    // 用指针访问结构体数组
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", comlist[i].quantity); // comlist[i]是一个结构体变量，可以用.来访问结构体变量的成员
        // 用指针去访问 ->访问结构体指针的成员
        printf("%d\n", (comlist + i)->quantity); // comlist是一个结构体指针，可以用->来访问结构体指针的成员
        // 指针的加法，指针加一个整数，指针会向后移动这个整数个类型的字节数
        // comlist[0] 是 结构体数组的第一个元素，是一个结构体变量
        // comlist 是 结构体数组的首地址，是一个结构体指针，指向结构体数组的第一个元素
        (comlist + i)->quantity = 100; // (comlist + i)是一个结构体指针，可以用->来访问结构体指针的成员
        printf("%d\n", (comlist + i)->quantity);
        (*(comlist + i)).quantity = 200; // *(comlist + i)是一个结构体变量，可以用.来访问结构体变量的成员
        printf("%d\n", (comlist + i)->quantity);
    }
    // 结构体成员的访问
    // 如果直接是结构体变量的话 .成员名 去访问结构体的成员
    // 如果是结构体指针的话 ->成员名 去访问结构体的成员

    struct commodity com4 = {"pear", 40};
    printf("%d\n", com4.quantity);
    struct commodity *com4_p = &com4;
    printf("%d\n", com4_p->quantity);

    free(comlist);  // 释放内存
    comlist = NULL; // 把comlist指向的地址设置为空

    // 二维数组
    int arr[2][3]; // 声明了一个二维数组，2行3列
                   // arr 代表什么？ 整个二维数组的首地址 int **类型，指针的指针
                   // arr[0],arr[1] 代表什么？ 第一行\第二行的数组的首地址 int *类型，指针
                   // arr[0][0] 代表什么？ 第一行第一列的元素 int类型
    // 动态分配内存空间，二维数组
    // 从外层到内层
    // 外层，两行数组
    // 内层 一行三列的一个一维数组
    int row = 2;                                      // 行
    int col = 3;                                      // 列
    int **arr2 = (int **)malloc(row * sizeof(int *)); // 一共有两行，每一行是一个int *类型的指针
    // arr2 是指针数组，存的是指针 arr2[0],arr2[1] 是指针,是int *类型的指针，是一维数组的指针=一维数组的变量名=一维数组的首地址=维数组第一个元素的地址
    for (int i = 0; i < row; i++)
    {
        // 每一行都是一个一维数组，有col个元素
        arr2[i] = (int *)malloc(col * sizeof(int)); // arr[i] 第i行的首地址，第i行的一维数组，第i行的变量名，第i行的第一个元素的地址
    }
    // arr2 是二维数组
    // arr2[0],arr2[1] 是一维数组
    // arr2[0][0],arr2[0][1],arr2[0][2] 是第一行的元素
    // arr2[1][0],arr2[1][1],arr2[1][2] 是第二行的元素
    // 二维数组的访问
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr2[i][j] = i * col + j; // 赋值
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr2[i][j]);
            // (arr2 + i)[j] 是第i行的第j个元素
            // *(arr2 + i * j) 是第i行的第j个元素
        }
        printf("\n");
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", *(*(arr2 + i)) + j);
            // 指针的计算 ++ -- +1 -1 一般是指针的加减一个整数
            //arr2 + i 是第i行一维数组的地址，数组的地址就是指针的指针
            //*(arr2 + i) 是第i行一维数组的地址值=第i行的第0个元素的地址，指针
            //*(arr2 + i) + j 是第i行的第j个元素的地址，指针
            //*(*(arr2 + i) + j) 是第i行的第j个元素
            printf("%d ", (*(arr2 + i))[j]);
            //*(arr2 + i) 是第i行一维数组的地址的值=第i行的第0个元素的地址，指针
            // (*(arr2 + i))[j] 是第i行的第j个元素
            // (*(arr2 + i))[j] = *(*(arr2 + i) + j) = arr2[i][j]
        }
        printf("\n");
    }
    // 释放内存
    for (int i = 0; i < row; i++)
    {
        free(arr2[i]); // 释放每一行的内存
    }
    free(arr2); // 释放arr2指向的内存
    arr2 = NULL; // 把arr2指向的地址设置为空
    return 0;
}