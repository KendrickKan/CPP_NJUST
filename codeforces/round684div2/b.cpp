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
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int len = n * k;
        vector<int> vec;
        rep(i, 0, len)
        {
            int x;
            cin >> x;
            vec.pb(x);
        }
        sort(vec.begin(), vec.end(), cmp);
        int zhong = (n - 1) / 2 + 1;
        int x = n - zhong + 1;
        ll ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += vec[len - (i + 1) * x];
        }
        cout << ans << endl;
    }
    return 0;
}