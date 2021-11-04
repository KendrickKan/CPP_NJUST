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
int main()
{
    int t;
    cin >> t;
    int xmin;
    xmin = t / 60;
    t %= 60;
    t = xmin + ((t == 0) ? -1 : 0);
    // int x = 3;
    // int ans = 2;
    // int a, b, c, d;
    // a = 0;
    // b = 1;
    // c = 1;
    // d = 1;
    if (t == 0)
        cout << 0;
    else if (t == 1 | t == 2 | t == 3)
        cout << 1;
    else
    {
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(1);
        vec.push_back(1);
        for (int i = 3; i <= t; i++)
        {
            vec.push_back((vec[i] + vec[i - 1] + vec[i - 2]) % 425);
        }
        //int m =vec.size();
        cout << vec[t];
        // while (x != t)
        // {
        //     ans %= 425;
        //     ans -= a;
        //     ans += d;
        //     a = b;
        //     b = c;
        //     c = d;
        //     d = ans;
        //     x++;
        // }
        // cout << ans % 425;
    }
    return 0;
}