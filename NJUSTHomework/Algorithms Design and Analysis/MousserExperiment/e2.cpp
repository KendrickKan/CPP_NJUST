#include <bits/stdc++.h>
using namespace std;
int n;
int w[100];
int v[100];
int V[100][10000];
int c;
int main()
{
    scanf("%d", &n); //输入个数
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]); //输入重量
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]); //输入价值
    }
    scanf("%d", &c); //输入背包重量
    for (int i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }
    for (int j = 0; j <= c; j++)
    {
        V[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            V[i][j] = V[i - 1][j];
            if (w[i] <= j)
            {
                V[i][j] = max(V[i][j], V[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d", V[n][c]);
    return 0;
}