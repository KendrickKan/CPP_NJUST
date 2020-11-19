/*
 * @Author: KendrickKan 
 * @Date: 2020-11-14 13:26:20 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-11-14 13:28:22
 */
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem0(a) memset(a, 0, sizeof(a))
#define memfu1(a) memset(a, -1, sizeof(a))
#define pb push_back
#define fi first
#define se second
#define EPS 1e-10
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 310;
int dir[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
int vis[maxn][maxn], sx, sy, tx, ty, n, cnt, mp[maxn][maxn];

typedef struct Node
{
    int x, y, step;
} Node;

void dbfs()
{
    memset(vis, 0, sizeof(vis));
    memset(mp, 0, sizeof(mp));
    cnt = 0;
    queue<Node> q0, q1;
    Node tmp, nxt;
    tmp.x = sx, tmp.y = sy, tmp.step = 0;
    vis[sx][sy] = 2;
    q0.push(tmp);
    tmp.x = tx, tmp.y = ty, tmp.step = 0;
    vis[tx][ty] = 1;
    q1.push(tmp);
    while (!q0.empty() || !q1.empty())
    {
        if (!q0.empty())
        {
            tmp = q0.front();
            q0.pop();
            for (int i = 0; i < 8; i++)
            {
                nxt.x = tmp.x + dir[i][0];
                nxt.y = tmp.y + dir[i][1];
                nxt.step = tmp.step + 1;
                if (nxt.x >= n || nxt.x < 0 || nxt.y >= n || nxt.y < 0 || vis[nxt.x][nxt.y] == 2)
                    continue;
                if (vis[nxt.x][nxt.y] == 1)
                {
                    cnt = nxt.step + mp[nxt.x][nxt.y];
                    return;
                }
                vis[nxt.x][nxt.y] = 2;
                mp[nxt.x][nxt.y] = nxt.step;
                q0.push(nxt);
            }
        }
        if (!q1.empty())
        {
            tmp = q1.front();
            q1.pop();
            for (int i = 0; i < 8; i++)
            {
                nxt.x = tmp.x + dir[i][0];
                nxt.y = tmp.y + dir[i][1];
                nxt.step = tmp.step + 1;
                if (nxt.x >= n || nxt.x < 0 || nxt.y >= n || nxt.y < 0 || vis[nxt.x][nxt.y] == 1)
                    continue;
                if (vis[nxt.x][nxt.y] == 2)
                {
                    cnt = nxt.step + mp[nxt.x][nxt.y];
                    return;
                }
                vis[nxt.x][nxt.y] = 1;
                mp[nxt.x][nxt.y] = nxt.step;
                q1.push(nxt);
            }
        }
    }
}

int main()
{
    FastIO;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cin >> sx >> sy >> tx >> ty;
        if (sx == tx && sy == ty)
        {
            cout << 0 << endl;
        }
        else
        {
            dbfs();
            cout << cnt << endl;
        }
    }

    return 0;
}