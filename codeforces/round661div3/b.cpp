#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    ll a[60], b[60];
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        ll mina = 1111111111, minb = 1111111111;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < mina)
                mina = a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] < minb)
                minb = b[i];
        }
        ll ans = 0;
        ll num;
        for (int i = 0; i < n; i++)
        {
            num = max(a[i] - mina, b[i] - minb);
            ans += num;
        }
        cout << ans << endl;
    }

    return 0;
}