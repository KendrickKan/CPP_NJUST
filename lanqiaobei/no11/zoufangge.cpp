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
const int MAXN = 35;
int dp[MAXN][MAXN];
int main()
{
    FastIO;
    int n, m;
    cin >> n >> m;
    repp(i, 1, n)
    {
        repp(j, 1, m)
        {
            if (i == 1 || j == 1)
                dp[i][j] = 1;
            else if (i % 2 == 0 && j % 2 == 0)
                dp[i][j] = -1;
            else
                //dp[i][j] = dp[i - 1][j]+ dp[i][j - 1];
                dp[i][j] = ((dp[i - 1][j] == -1) ? 0 : dp[i - 1][j]) + ((dp[i][j - 1] == -1) ? 0 : dp[i][j - 1]);
        }
    }
    cout << ((dp[n][m] == -1) ? 0 : dp[n][m]);
    return 0;
}