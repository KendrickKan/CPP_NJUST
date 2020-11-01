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
        int n;
        cin >> n;
        int a[100005];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll ans = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                int x = (-1) * a[i];
                if (sum > 0)
                {
                    if (x <= sum)
                        sum -= x;
                    else
                    {
                        ans += (x - sum);
                        sum = 0;
                    }
                }
                else
                {
                    ans += (x - sum);
                }
            }
            else
            {
                sum += a[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}