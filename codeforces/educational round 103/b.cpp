/*
 * @Author: KendrickKan 
 * @Date: 2021-01-29 22:47:44 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-01-29 23:19:06
 */
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem0(a) memset(a, 0, sizeof(a))
#define memfu1(a) memset(a, -1, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define EPS 1e-10
const int MOD = 1e9 + 7;
//INT_MAX <limits>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[205];
        mem0(a);
        ll num = 0;
        rep(i, 0, n)
        {
            cin >> a[i];
            num += a[i];
        }
        ll ans = 0 * 1ll;
        for (int i = n - 2; i >= 0; i--)
        {
            double x = a[i + 1] * 1.0;
            double y = num * 1.0 - a[i + 1];
            ll m = 0;
            if (x * 1.0 * 100 > k * 1.0 * y)
                m = ceill(100 * 1.0 * x / k - y) * 1ll;
            y += m;
            ans += m;
            num = y;
        }
        cout << ans << endl;
    }
    return 0;
}