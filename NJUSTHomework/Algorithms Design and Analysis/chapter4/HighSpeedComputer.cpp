#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int f1[MAXN][MAXN][MAXN];
//f1[p][i][j]表示第p个节点执行i个A任务，j个B任务的最短时间
int f2[MAXN][MAXN][MAXN];
//f2[p][i][j]表示前p个节点执行i个A任务，j个B任务的最短时间
int p, ta[MAXN], tb[MAXN], ka[MAXN], kb[MAXN];
int na, nb;
void DP1()
{
    for (int a = 1; a <= p; ++a)
    {
        int F[2][MAXN][MAXN];
        memset(F, 31, sizeof(F));
        F[1][0][0] = F[0][0][0] = 0;
        for (int i = 0; i <= na; ++i)
            for (int j = 0; j <= nb; ++j)
            {
                for (int k = 1; k <= i; ++k)
                    F[0][i][j] = min(F[0][i][j], F[1][i - k][j] + ka[a] * k * k + ta[a]);
                for (int k = 1; k <= j; ++k)
                    F[1][i][j] = min(F[1][i][j], F[0][i][j - k] + kb[a] * k * k + tb[a]);
                f1[a][i][j] = min(F[0][i][j], F[1][i][j]);
            }
    }
}
void DP2()
{
    memset(f2, 31, sizeof(f2));
    for (int i = 0; i <= na; ++i)
        for (int j = 0; j <= nb; ++j)
            f2[1][i][j] = f1[1][i][j];
    for (int a = 2; a <= p; ++a)
    {
        for (int i = 0; i <= na; ++i)
            for (int j = 0; j <= nb; ++j)
                for (int k = 0; k <= i; ++k)
                    for (int l = 0; l <= j; ++l)
                        f2[a][i][j] = min(f2[a][i][j], max(f2[a - 1][k][l], f1[a][i - k][j - l]));
    }
}
int main()
{
    cin >> na;
    cin >> nb;
    cin >> p;
    for (int i = 1; i <= p; ++i)
        cin >> ta[i] >> tb[i] >> ka[i] >> kb[i];
    DP1();
    DP2();
    cout << f2[p][na][nb] << endl;
    return 0;
}