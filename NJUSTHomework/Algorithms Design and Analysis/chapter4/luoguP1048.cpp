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
const int MAXN = 105;
int a[2][MAXN];
int dp[MAXN][1005];
int main()
{
    FastIO;
    int t, m;
    cin >> t >> m;
    repp(i, 1, m)
    {
        cin >> a[0][i] >> a[1][i];
    }
    repp(i, 0, m)
    {
        dp[i][0] = 0;
    }
    repp(i, 0, t)
    {
        dp[0][i] = 0;
    }
    repp(i, 1, m)
    {
        repp(j, 1, t)
        {
            if (j < a[0][i])
                dp[i][j] = dp[i - 1][j];
            else if (j >= a[0][i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[0][i]] + a[1][i]);
        }
    }
    cout << dp[m][t];
    return 0;
}