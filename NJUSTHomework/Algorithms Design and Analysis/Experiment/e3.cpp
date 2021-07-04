#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n;
int cost[MAXN][MAXN];
int bestL[MAXN]; //最佳路径
int cL[MAXN];    //当前路径
int bestCo = -1; //当前最低耗费
int cCo = 0;     //当前耗费

void TSP(int t)
{
    if (t == n)
    {
        if (cost[cL[n - 1]][n] != -1 && cost[cL[n]][1] != -1 && (bestCo == -1 || cCo + cost[cL[n - 1]][n] + cost[cL[n]][1] < bestCo))
        {
            bestCo = cCo + cost[cL[n - 1]][n] + cost[cL[n]][1];
            copy(cL + 1, cL + n + 1, bestL + 1);
        }
    }
    else
    {
        for (int j = t; j <= n; ++j)
            if (cost[cL[t - 1]][cL[j]] != -1 && (bestCo == -1 || cCo + cost[cL[t - 1]][cL[j]] < bestCo))
            {
                swap(cL[t], cL[j]);
                cCo += cost[cL[t - 1]][cL[t]];
                TSP(t + 1);
                cCo -= cost[cL[t - 1]][cL[t]];
                swap(cL[t], cL[j]);
            }
    }
}
int main()
{
    cout << "请输入顶点个数:";
    cin >> n;
    for (int i = 1; i <= n; i++)
        cL[i] = i;
    memset(cost, -1, sizeof(cost));
    int s;
    cout << "请输入边条数:";
    cin >> s;
    cout << "请依次输入边的两个顶点和边权:" << endl;
    for (int i = 1; i <= s; i++)
    {
        int x, y, co;
        cin >> x >> y >> co;
        cost[x][y] = co;
        cost[y][x] = co;
    }
    TSP(2);

    cout << "最少的运费为:" << bestCo << endl;
    cout << "最佳路径为: ";
    for (int i = 1; i <= n; i++)
    {
        cout << bestL[i] << "->";
    }
    cout << bestL[1] << endl;
    return 0;
}