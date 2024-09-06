#include <iostream>
using namespace std;
char map[1000][1000];
int visit[1000][1000] = {0};
int X[100005];
int Y[100005];
int r, c = 0;
int boundary(int x, int y)
{
    if (x >= 1 && x <= r && y >= 1 && y <= r && visit[x][y] == 0 && map[x][y] != '*')
    {
        return 1;
    }
    return 0;
}
void dfs(int x, int y, int step)
{
    int next[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    X[step] = x;
    Y[step] = y;
    visit[x][y] = 1;
    if (x == r && y == c)
    {
        for (int i = 1; i <= step; i++)
        {
            cout << X[i] << " " << Y[i];
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (boundary(x + next[i][0], y + next[i][1]))
            dfs(x + next[i][0], y + next[i][1], step + 1);
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> map[i][j];
    dfs(1, 1, 1);
    return 0;
}