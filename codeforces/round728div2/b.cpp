//题目的意思是 对于每一个i,j 输出使得a[i]*a[j]==i+j的(i,j)对的数量
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
ll a[100005];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        repp(i, 1, n)
        {
            cin >> a[i];
        }
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            //这种的话就是暴力 肯定会超时
            // repp(j, i + 1, n)
            // {
            //     if (a[i] * a[j] == i + j)
            //         ans++;
            // }
            //这种方法判断的是
            //如果a[i]*a[j]==i+j
            //那么a[i]肯定能被i+j整除
            //那么枚举j+i=x*a[i]   x={1,2,3...}
            for (ll j = a[i] - i; j <= n; j += a[i])
            {
                //避免重复 如果j<=i的话就已经被计算过了 我们这讨论的是i<=j的情况 避免重复计算
                // 这里的重复指的是 (1,2) (2,1)就算是重复计算
                if (j <= i)
                    continue;
                if (a[i] * a[j] == i + j)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}