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
    int n, m;
    cin >> n >> m;
    ll a[205], b[205], c[205];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    ll min = 9999999999;
    for (int i = 0; i < n; i++)
    {
        min = 9999999999;
        for (int j = 0; j < m; j++)
            if ((a[i] & b[j]) < min)
                min = a[i] & b[j];
        c[i] = min;
    }
    ll x = c[0];
    for (int i = 1; i < n; i++)
        x = x | c[i];
    cout << x;
    return 0;
}