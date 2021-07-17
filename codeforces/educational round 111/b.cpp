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
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string str;
        cin >> str;
        char now = str[0];
        int num = 1;
        int tt[2];
        mem0(tt);
        tt[(str[0] - '0') % 2]++;
        for (int i = 1; i < str.length(); i++)
        {
            if (now != str[i])
            {
                now = str[i];
                tt[(str[i] - '0') % 2]++;
            }
        }
        int f = 1;
        if (tt[0] == 0 || tt[1] == 0)
        {
            f = 0;
            num = 1;
        }
        else
            num = min(tt[0], tt[1]);
        if (b >= 0)
        {
            cout << (a + b) * n << endl;
        }
        else
        {
            cout << a * n + b * (num + f) << endl;
        }
    }
    return 0;
}