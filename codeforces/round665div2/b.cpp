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
    while (t--)
    {
        ll x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        ll n = x1 + y1 + z1;
        ll ans = 0;
        if (z1 >= y2)
        {
            ans += 2 * y2;
            z1 -= y2;
            y2 = 0;
        }
        else
        {
            ans += 2 * z1;
            y2 -= z1;
            z1 = 0;
        }
        ll a = z2 - x1 - z1;
        if (a > 0)
            ans -= 2 * a;
        cout << ans << endl;
    }

    return 0;
}