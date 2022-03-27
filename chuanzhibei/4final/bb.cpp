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
int splitArray(vector<ll> &nums, int m)
{
    int n = nums.size();
    vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
    vector<long long> sub(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        sub[i + 1] = sub[i] + nums[i];
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(i, m); j++)
        {
            for (int k = 0; k < i; k++)
            {
                f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
            }
        }
    }
    return (int)f[n][m];
}
int main()
{
    FastIO;
    int n, k;
    cin >> n >> k;
    vector<ll> vec;
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        vec.push_back(x * x);
    }
    cout << splitArray(vec, k);
    return 0;
}