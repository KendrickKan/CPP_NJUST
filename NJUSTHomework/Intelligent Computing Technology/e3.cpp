#include <bits/stdc++.h>
using namespace std;
// 蚁群算法解决旅行商问题
const int MAX = 10000; // 最大迭代次数
const int N = 100;     // 城市数量
const int M = 200;     // 蚂蚁数量
const int Q = 2000;    // 信息素总量
const double kalpha = 1.0;
const double kbeta = 2.0;
const double rho = 0.1;   // 信息素挥发速度
int city[N][N];           // 城市距离
int path[M][N];           // 蚂蚁路径
int pathlength[M];        // 蚂蚁路径长度
int bestpath[N];          // 最佳路径
int bestlength = INT_MAX; // 最佳路径长度
double pheromone[N][N];   // 信息素
double prob[N];           // 选择下一个城市的概率
int visited[M][N];        // 蚂蚁访问过的城市
int visitednum[M];        // 蚂蚁访问过的城市数量
int unvisited[M][N];      // 蚂蚁未访问过的城市
int unvisitednum[M];      // 蚂蚁未访问过的城市数量
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                city[i][j] = 10000;
                continue;
            }
            while (city[i][j] <= 0)
            {
                city[i][j] = rand() % 100;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            pheromone[i][j] = Q / N;
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
            unvisited[i][j] = 1;
        }
        visitednum[i] = 0;
        unvisitednum[i] = N;
    }
    for (int i = 0; i < M; i++)
    {
        pathlength[i] = 0;
        int start = rand() % N;
        path[i][0] = start;
        visited[i][start] = 1;
        visitednum[i]++;
        unvisited[i][start] = 0;
        unvisitednum[i]--;
    }
}

void antmove()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            double sum = 0;
            for (int k = 0; k < N; k++)
            {
                if (unvisited[i][k] == 1)
                {
                    sum += pow(pheromone[path[i][j - 1]][k], kalpha) * pow(1.0 / city[path[i][j - 1]][k], kbeta);
                }
            }
            for (int k = 0; k < N; k++)
            {
                if (unvisited[i][k] == 1)
                {
                    prob[k] = pow(pheromone[path[i][j - 1]][k], kalpha) * pow(1.0 / city[path[i][j - 1]][k], kbeta) / sum;
                }
                else
                {
                    prob[k] = 0;
                }
            }
            double p = (double)rand() / RAND_MAX;
            double temp = 0;
            for (int k = 0; k < N; k++)
            {
                temp += prob[k];
                if (temp >= p)
                {
                    path[i][j] = k;
                    break;
                }
            }
            visited[i][path[i][j]] = 1;
            visitednum[i]++;
            unvisited[i][path[i][j]] = 0;
            unvisitednum[i]--;
        }
    }
}
void updatepath()
{
    for (int i = 0; i < M; i++)
    {
        pathlength[i] = 0;
        for (int j = 0; j < N - 1; j++)
        {
            pathlength[i] += city[path[i][j]][path[i][j + 1]];
        }
        pathlength[i] += city[path[i][N - 1]][path[i][0]];
        if (pathlength[i] < bestlength)
        {
            bestlength = pathlength[i];
            for (int j = 0; j < N; j++)
            {
                bestpath[j] = path[i][j];
            }
        }
    }
}
void updatepheromone()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            pheromone[i][j] *= (1 - rho);
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            pheromone[path[i][j]][path[i][j + 1]] += Q / pathlength[i];
        }
        pheromone[path[i][N - 1]][path[i][0]] += Q / pathlength[i];
    }
}
int main()
{
    srand(time(0));
    init();
    for (int i = 0; i < MAX; i++)
    {
        antmove();
        updatepath();
        updatepheromone();
    }

    cout << "最佳路径长度为：" << bestlength << endl;
    cout << "最佳路径为：";
    for (int i = 0; i < N; i++)
    {
        cout << bestpath[i] << " ";
    }
    cout << bestpath[0] << " ";
    cout << endl;
    return 0;
}