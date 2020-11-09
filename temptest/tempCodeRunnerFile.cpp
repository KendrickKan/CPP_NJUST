/*
 * @Author: KendrickKan 
 * @Date: 2020-11-09 16:32:50 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-11-09 17:21:29
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
int l, r, c;
int beginx, beginy, beginz;
int overx, overy, overz;
struct node
{
    int x, y, z;
    int step;
};
char mp[55][55][55];
bool vis[55][55][55];
int dir[6][3] = {{0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}};
bool check(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0 || x >= l || y >= r || z >= c || mp[x][y][z] == '#' || vis[x][y][z] == 1)
        return false;
    return true;
}
int bfs()
{
    node nown, nextn;
    nown.x = beginx;
    nown.y = beginy;
    nown.z = beginz;
    vis[beginx][beginy][beginz] = 1;
    nown.step = 0;
    queue<node> q;
    q.push(nown);
    while (!q.empty())
    {
        nown = q.front();
        q.pop();
        if (mp[nown.x][nown.y][nown.z] == 'E')
            return nown.step;
        rep(i, 0, 6)
        {
            //int temp1 = dir[i][0];
            //int temp2 = dir[i][1];
            //int temp3 = dir[i][2];
            nextn.x = nown.x + dir[i][0];
            nextn.y = nown.y + dir[i][1];
            nextn.z = nown.z + dir[i][2];
            if (check(nextn.x, nextn.y, nextn.z))
            {
                vis[nextn.x][nextn.y][nextn.z] = 1;
                nextn.step = nown.step + 1;
                q.push(nextn);
            }
        }
    }
    return 0;
}
int main()
{
    FastIO;
    while (cin >> l >> r >> c && (l || r || c))
    {
        rep(i, 0, l)
        {
            rep(j, 0, r)
            {
                rep(k, 0, c)
                {
                    cin >> mp[i][j][k];
                    if (mp[i][j][k] == 'S')
                    {
                        beginx = i;
                        beginy = j;
                        beginz = k;
                    }
                    if (mp[i][j][k] == 'E')
                    {
                        overx = i;
                        overy = j;
                        overz = k;
                    }
                }
            }
        }
        mem0(vis);
        int ans = bfs();
        if (ans)
            cout << "Escaped in " << ans << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
    }
    return 0;
}