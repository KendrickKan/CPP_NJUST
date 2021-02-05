/*
 * @Author: KendrickKan 
 * @Date: 2021-02-05 17:31:25 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-02-05 20:49:15
 */
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
const int N = 105;
int a[N], b[N], c[N], d[N], e[N];

int main()
{
    ll ret = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> c[i] >> d[i];

    for (int mask = 1; mask < (1 << k); mask++)
    {
        ll cur = 0;
        fill(e, e + N, 0);
        for (int j = 0; j < k; j++)
        {
            if ((1 << j) & mask)
            {
                e[d[j]]++;
            }
            else
            {
                e[c[j]]++;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (e[a[i]] && e[b[i]])
            {
                cur++;
            }
        }
        ret = max(ret, cur);
    }
    cout << ret;
    return 0;
}