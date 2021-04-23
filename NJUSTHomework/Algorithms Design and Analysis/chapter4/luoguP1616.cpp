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
const int MAXN = 10005;
int t, m;
int w[MAXN];
int v[MAXN];
int dp[MAXN][MAXN];
int main()
{
    FastIO;
    read(t);
    read(m);
    rep(i, 0, m)
    {
        int x, y;
        read(x);
        read(y);
        w[i] = x;
        v[i] = y;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            if (i > 1)
            {
                dp[i][j] = dp[i - 1][j];
                if (j / w[i] >= 1)
                {
                    int maxTmp = 0;
                    // 对于i个物品，进行j/w[i]次比较得到最大值；而01背包中只需要进行1次比较
                    for (int k = 1; k <= j / w[i]; k++)
                    {
                        if (dp[i - 1][j - k * w[i]] + k * v[i] > maxTmp)
                        {
                            maxTmp = dp[i - 1][j - k * w[i]] + k * v[i];
                        }
                    }
                    dp[i][j] = max(dp[i][j], maxTmp);
                }
            }
            else
            {
                if (j / w[1] >= 1)
                {
                    dp[1][j] = j / w[1] * v[1];
                }
            }
        }
    }
    cout << dp[m][t] << endl;
    return 0;
}