#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (n == 1 || m == 0)
            cout << 0 << endl;
        else
        {

            ll x = n / 2;
            if (m >= x)
                cout << n * (n - 1) / 2 << endl;
            else
            {
                cout << n * (n - 1) - m * m - (n - m) * (n - 1 - m) << endl;
            }
        }
    }

    return 0;
}