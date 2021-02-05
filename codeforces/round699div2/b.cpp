#include <bits/stdc++.h>
using namespace std;
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
int a[105];
bool check(int n)
{
    rep(i, 0, n - 1)
    {
        if (a[i] < a[i + 1])
            return false;
    }
    return true;
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
        mem0(a);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        rep(i, 0, k)
        {
            if (check(n))
            {
                cout << -1 << endl;
                break;
            }
            else
            {
                if (i < k - 1)
                {
                    rep(i, 0, n - 1)
                    {
                        if (a[i] < a[i + 1])
                        {
                            a[i]++;
                            break;
                        }
                    }
                }
                else
                {
                    rep(i, 0, n - 1)
                    {
                        if (a[i] < a[i + 1])
                        {
                            cout << i + 1 << endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}