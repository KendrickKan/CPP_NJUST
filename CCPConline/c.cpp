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
        ll n, k, m;
        cin >> n >> m >> k;
        unsigned long long ans = 2 * (k - 1);
        ll temp;
        ll minn = 1e10;
        for (int i = 0; i < m; i++)
        {
            cin >> temp;
            if (minn > temp)
                minn = temp;
            ans += abs(temp - k) * 2;
        }

        if (minn < k)
            ans += 2*(minn - k);
        //ans += minn - 1 - (k - minn);
        /*else
        {
            ans += minn - 1 + (k - minn);
        }*/

        cout << ans << endl;
    }
    return 0;
}