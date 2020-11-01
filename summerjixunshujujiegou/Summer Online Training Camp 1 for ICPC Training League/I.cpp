#include <iostream>
using namespace std;
char board[4][4];
int ans, n, node[4][4];

bool judge(int x, int y)
{
    for (int i = x; i >= false && board[i][y] != 'X'; i--)
        if (node[i][y])
            return false;
    for (int i = x; i < n && board[i][y] != 'X'; i++)
        if (node[i][y])
            return false;
    for (int i = y; i >= false && board[x][i] != 'X'; i--)
        if (node[x][i])
            return false;
    for (int i = y; i < n && board[x][i] != 'X'; i++)
        if (node[x][i])
            return false;
    return true;
}

void dfs(int x, int y, int sum)
{
    if (x == n)
    {
        ans = (sum > ans ? sum : ans);
        return;
    }

    if (board[x][y] != 'X' && judge(x, y))
    {
        node[x][y] = 1;
        dfs(x + (y + 1) / n, (y + 1) % n, sum + 1);
        node[x][y] = 0;
    }
    dfs(x + (y + 1) / n, (y + 1) % n, sum);
}

int main()
{
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> board[i];
        ans = 0;
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}