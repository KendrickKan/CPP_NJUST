#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fo(x) for (register int i = 1; i <= x; ++i)
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
// INT_MAX <limits>
#define PI acos(-1)
template <typename T>
void read(T &t)
{
    t = 0;
    char ch = getchar();
    int f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    do
    {
        (t *= 10) += ch - '0';
        ch = getchar();
    } while ('0' <= ch && ch <= '9');
    t *= f;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[300005];
int q[300005];
int vis[300005];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        mem0(vis);
        int n, m, k;
        cin >> n >> m >> k;
        repp(i, 1, m)
        {
            cin >> a[i];
        }
        repp(i, 1, k)
        {
            cin >> q[i];
            vis[q[i]] = 1;
        }
        if (k >= n)
        {
            cout << string(m, '1') << endl;
            continue;
        }
        else if (k < n - 1)
        {
            cout << string(m, '0') << endl;
            continue;
        }
        else
        {
            int flag = 0;
            repp(i, 1, n)
            {
                if (vis[i] == 0)
                {
                    flag = i;
                    break;
                }
            }
            repp(i, 1, m)
            {
                if (a[i] == flag)
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
                }
            }
            cout << endl;
        }
    }
    return 0;
}