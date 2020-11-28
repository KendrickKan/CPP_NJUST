#include <bits/stdc++.h>
using namespace std;
int vis[205];
bool ifvis(int x)
{
    for (int i = 1; i <= x; i++)
    {
        if (vis[i] != 1)
            return false;
    }
    return true;
}
int main()
{
    int n, num;
    cin >> n >> num;
    int a[205][205];
    memset(a, 0, sizeof(a));
    while (num--)
    {
        int x, y, co;
        cin >> x >> y;
        cin >> co;
        a[x][y] = co;
    }
    //int vis[205];
    int t;
    cin >> t;
    int ans = 0;
    int biao = 0;
    long long huafie = 1000000000000;
    for (int i = 1; i <= t; i++)
    {
        int qian = 0;
        memset(vis, 0, sizeof(vis));
        bool iff = false;
        int nowhuafei = 0;
        int q;
        cin >> q;
        while (q--)
        {
            int temp;
            cin >> temp;
            vis[temp]++;
            if (a[qian][temp] != 0 || a[temp][qian] != 0)
            {
                nowhuafei += a[qian][temp];
                nowhuafei += a[temp][qian];
            }
            else
            {
                iff = true;
                break;
            }
            qian = temp;
        }
        nowhuafei += a[qian][0];
        nowhuafei += a[0][qian];
        if (a[qian][0] == 0 && a[0][qian] == 0)
            iff = true;
        if (ifvis(n) && !iff)
        {
            ans++;
            if (nowhuafei < huafie)
            {
                biao = i;
                huafie = nowhuafei;
            }
        }
    }
    cout << ans << endl;
    cout << biao << " " << huafie << endl;
    return 0;
}