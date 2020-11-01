#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
int main()
{
    IOS;
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int a[105][105];
    memset(a, 0, sizeof(a));
    for (int i = y; i <= m; i++)
    {
        cout << x << ' ' << i << endl;
    }
    for (int i = y - 1; i >= 1; i--)
    {
        cout << x << ' ' << i << endl;
    }
    int zanshiy;
    int flag = 1;
    for (int i = x - 1; i >= 1; i--)
    {
        if (flag % 2)
        {
            for (int j = 1; j <= m; j++)
                cout << i << ' ' << j << endl;
            flag++;
            zanshiy = m;
        }
        else
        {
            for (int j = m; j >= 1; j--)
                cout << i << ' ' << j << endl;
            flag++;
            zanshiy = 1;
        }
    }
    if (zanshiy == 1)
        flag = 1;
    else
        flag = 0;
    for (int i = x + 1; i <= n; i++)
    {
        if (flag % 2)
        {
            for (int j = 1; j <= m; j++)
                cout << i << ' ' << j << endl;
            flag++;
        }
        else
        {
            for (int j = m; j >= 1; j--)
                cout << i << ' ' << j << endl;
            flag++;
        }
    }
    return 0;
}