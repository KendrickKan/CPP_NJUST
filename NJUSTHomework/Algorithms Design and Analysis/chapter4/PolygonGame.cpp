#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5;
int N;
int v[MAXN];
char op[MAXN];
int dpmin[MAXN][MAXN];
int dpmax[MAXN][MAXN];
int kmin(int a, int b, int c, int d, int e)
{
    return min(a, min(b, min(c, min(d, e))));
}
int kmax(int a, int b, int c, int d, int e)
{
    return max(a, max(b, max(c, max(d, e))));
}
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> op[i] >> v[i];
        dpmin[i][0] = v[i];
        dpmax[i][0] = v[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int l = 1; l <= N; l++)
        {
            dpmin[i][l] = 1e9 + 7;
            dpmax[i][l] = -1e9 + 7;
            for (int t = 0; t <= l; t++)
            {
                if (op[(i + (t - 1)) % (N + 1)] == '+')
                    dpmin[i][l] = min(dpmin[i][t] + dpmin[(i + t) % (N + 1)][l - t - 1], dpmin[i][l]);
                else
                    dpmin[i][l] = kmin(dpmin[i][t] * dpmin[(i + t) % (N + 1)][l - t - 1],
                                       dpmin[i][t] * dpmax[(i + t) % (N + 1)][l - t - 1],
                                       dpmax[i][t] * dpmin[(i + t) % (N + 1)][l - t - 1],
                                       dpmax[i][t] * dpmax[(i + t) % (N + 1)][l - t - 1],
                                       dpmin[i][l]);
                if (op[(i + (t - 1)) % (N + 1)] == '+')
                    dpmax[i][l] = max(dpmax[i][t] + dpmax[(i + t) % (N + 1)][l - t - 1], dpmax[i][l]);
                else
                    dpmax[i][l] = kmax(dpmin[i][t] * dpmin[(i + t) % (N + 1)][l - t - 1],
                                       dpmin[i][t] * dpmax[(i + t) % (N + 1)][l - t - 1],
                                       dpmax[i][t] * dpmin[(i + t) % (N + 1)][l - t - 1],
                                       dpmax[i][t] * dpmax[(i + t) % (N + 1)][l - t - 1],
                                       dpmax[i][l]);
            }
        }
    }
    for (int i = 1; i <= N; i++)
        cout << dpmax[i][N - 1] << " ";
    return 0;
}