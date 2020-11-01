#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll l, r;
    while (cin >> l >> r)
    {
        ll k = sqrt(r), ans = 0;
        for (int i = 2; i <= k; i++)
        {
            ll tmp = (l - 1) / i;
            for (ll j = tmp + 1; j * i <= r; j++)
            {
                if (j <= k)
                    ans += i;
                else
                    ans += i + j;
            }
        }
        for (ll i = l; i <= r; i++)
        {
            if (i > k)
                ans += i + 1;
            else
                ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}