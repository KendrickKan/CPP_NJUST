/*
 * @Author: KendrickKan 
 * @Date: 2021-01-29 23:26:14 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-01-30 00:34:53
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
int a[100005];
int b[100005];
int c[100005];
ll dp[100005];
bool cmp(ll a, ll b)
{
    return a > b;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        rep(i, 0, n)
        {
            cin >> b[i];
        }
        rep(i, 0, n)
        {
            cin >> c[i];
        }
        ll ans = 0;
        dp[0] = 0;
        rep(i, 1, n)
        {
            if (b[i] != c[i])
            {
                dp[i] = max(dp[i - 1] - abs(c[i] - b[i]), abs(c[i] - b[i]) * 1ll) + a[i] + 1;
            }
            else
                dp[i] = a[i] + 1;
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}