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
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[105];
        int b[105];
        mem0(a);
        mem0(b);
        int x;
        rep(i, 0, n)
        {
            cin >> x;
            a[x]++;
        }
        rep(i, 0, m)
        {
            cin >> x;
            b[x]++;
        }
        int ans = 0;
        rep(i, 0, 105)
        {
            if (a[i] == b[i] && a[i] != 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}