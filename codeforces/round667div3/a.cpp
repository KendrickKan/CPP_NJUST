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
        ll a, b;
        cin >> a >> b;
        ll x = abs(a - b);
        ll ans;
        if (x % 10 == 0)
            ans = x / 10;
        else
        {
            ans = x / 10 + 1;
        }
        cout << ans << endl;
    }

    return 0;
}