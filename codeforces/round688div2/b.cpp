//ctrl alt i new-head
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
int a[200005];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        mem0(a);
        int mxnum = 0;
        int loc;
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        rep(i, 1, n - 1)
        {
            if (abs((a[i] - a[i - 1]) - (a[i + 1] - a[i])) > mxnum)
            {
                mxnum = abs((a[i] - a[i - 1]) - (a[i + 1] - a[i]));
                loc = i;
            }
        }
        a[loc] = a[loc - 1];
        // int xiao = 0, da = 0;
        // if (loc >= 1)
        // {
        //     a[loc] = a[loc - 1];
        // }
        // else
        // {
        //     a[loc] = a[loc + 1];
        // }

        int num = a[0];
        ll ans = 0;
        ll temp = 0;
        for (int i = 1; i < n; i++)
        {
            ans += abs(-1 * temp + num - a[i]);
            temp += -1 * temp + num - a[i];
        }
        cout << ans << endl;
    }
    return 0;
}