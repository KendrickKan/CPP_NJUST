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
    for (int i = 1; i <= t; i++)
    {
        ll ans = 0;
        ll n, a, b;
        cin >> n >> a >> b;
        int x, y;
        cin >> x;
        ans = b * n + a * 2;
        //bool where = 0;
        for (int j = 1; j < n; j++)
        {
            cin >> y;
            if ((y - x - 1) * b < (a * 2))
                ans += (y - x - 1) * b;
            else
            {
                ans += a * 2;
            }
            x = y;
        }
        cout << "Case #" << i << ": ";
        cout << ans << endl;
    }
    return 0;
}