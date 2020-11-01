#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int map[26][26] = {0};
bool visit[26][26] = {0};

int best = -999;
void dfs(int u, int n, int cnt)
{
    if (cnt > best)
        best = cnt;
    for (int i = 0; i < n; i++)
    {
        if (map[u][i] && !visit[u][i])
        {
            visit[u][i] = visit[i][u] = true;
            dfs(i, n, cnt + 1);
            visit[u][i] = visit[i][u] = false;
        }
    }
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int x, y;
        if (n == 0 && m == 0)
            break;
        memset(map, false, sizeof(map));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            map[x][y] = map[y][x] = true;
        }
        best = -999;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (map[i][j])
                {
                    visit[i][j] = visit[j][i] = true;
                    dfs(j, n, 1);
                    visit[i][j] = visit[j][i] = false;
                }
        printf("%d\n", best);
    }
    return 0;
}