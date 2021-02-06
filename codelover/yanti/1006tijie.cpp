#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int line[1001][1001], vis[1001], pre[1001];

bool DFS(int x)
{
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i] && line[x][i])
        {
            vis[i] = 1;
            if (!pre[i] || DFS(pre[i]))
            {
                pre[i] = x;
                return true;
            }
        }
    }
    return false;
}

map<int, int> mp;

int main()
{
    int i, ans = 0;
    cin >> M >> N >> K;
    memset(pre, 0, sizeof(pre));
    memset(line, 0, sizeof(line));
    for (i = 1; i <= M; i++)
    {
        int temp;
        cin >> temp;
        mp[temp] = 1;
    }
    for (i = 1; i <= K; i++)
    {
        int a, b;
        cin >> a >> b;
        if (mp[b] != 1)
            line[a][b] = 1;
    }
    for (i = 1; i <= M; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (DFS(i))
            ans++;
    }
    //  cout<<ans<<endl;
    if (ans == M)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
