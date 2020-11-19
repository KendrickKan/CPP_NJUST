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
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string str;
        cin >> str;
        int zeronum, onenum;
        zeronum = onenum = 0;
        rep(i, 0, n)
        {
            if (str[i] == '0')
                zeronum++;
            else
                onenum++;
        }
        int ans = 0;
        if ((c0 + h) < (c1))
        {
            ans += c0 * zeronum;
            ans += (c0 + h) * onenum;
        }
        else if ((c1 + h) < c0)
        {
            ans += c1 * onenum;
            ans += (c1 + h) * zeronum;
        }
        else
        {
            ans += c1 * onenum + c0 * zeronum;
        }

        cout << ans << endl;
    }
    return 0;
}