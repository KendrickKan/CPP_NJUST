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
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        string str;
        cin >> str;
        int u = 0, d = 0, r = 0, l = 0;
        rep(i, 0, str.length())
        {
            if (str[i] == 'R')
                r++;
            if (str[i] == 'L')
                l++;
            if (str[i] == 'U')
                u++;
            if (str[i] == 'D')
                d++;
        }
        bool flag1 = false;
        bool flag2 = false;
        if (x == 0)
            flag1 = true;
        else if (x < 0)
        {
            if (l >= abs(x))
                flag1 = true;
        }
        else if (x > 0)
        {
            if (r >= x)
                flag1 = true;
        }
        if (y == 0)
            flag2 = true;
        else if (y < 0)
        {
            if (d >= abs(y))
                flag2 = true;
        }
        else if (y > 0)
        {
            if (u >= y)
                flag2 = true;
        }
        if (flag1 && flag2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}