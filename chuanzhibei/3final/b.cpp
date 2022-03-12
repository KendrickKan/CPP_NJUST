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
bool cmp(int a, int b)
{
    return (a > b); //降序
}
int main()
{
    FastIO;
    int n, m;
    cin >> n >> m;
    vector<int> w;
    vector<int> c;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        w.pb(x);
    }
    sort(w.begin(), w.end(), cmp);
    rep(i, 0, m)
    {
        int x;
        cin >> x;
        c.pb(x);
    }
    sort(c.begin(), c.end(), cmp);
    int count = 0;
    rep(i, 0, n)
    {
        if (c.size() == 0)
            break;
        if (w.back() >= c.back())
        {
            count++;
            c.pop_back();
        }
        w.pop_back();
    }
    cout << count;
    return 0;
}