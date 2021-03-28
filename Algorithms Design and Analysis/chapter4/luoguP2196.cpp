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
const int MAXN = 25;
int n;
int w[MAXN];
int kmap[MAXN][MAXN];
int dp[MAXN];
int pre[MAXN];
int ans, pos;
int main()
{
    FastIO;
    read(n);
    repp(i, 1, n)
    {
        read(w[i]);
    }
    rep(i, 1, n)
    {
        repp(j, 1, n - i)
        {
            read(kmap[i][j]);
        }
    }
    dp[1] = w[1];
    repp(i, 2, n)
    {
        dp[i] = w[i];
        rep1(j, i - 1, 0)
        {
            if (kmap[j][i - j] && dp[i] < (dp[j] + w[i])) //这里的kamp[j][i-j]很有意思
            {
                dp[i] = dp[j] + w[i];
                pre[i] = j;
            }
        }
        if (ans < dp[i])
        {
            ans = dp[i];
            pos = i;
        }
    }
    stack<int> sta;
    while (pre[pos])
    {
        sta.push(pos);
        pos = pre[pos];
    }
    sta.push(pos);
    while (!sta.empty())
    {
        cout << sta.top() << " ";
        sta.pop();
    }
    cout << endl
         << ans << endl;
    return 0;
}