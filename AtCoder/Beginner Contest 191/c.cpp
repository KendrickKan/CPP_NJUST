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
char a[15][15];
bool vis[15][15];
int main()
{
    FastIO;
    int h, w;
    cin >> h >> w;
    rep(i, 0, h)
    {
        rep(j, 0, w)
        {
            cin >> a[i][j];
        }
    }
    int b[4][15];
    mem0(b);
    int ans = 0;
    rep(i, 1, w - 1)
    {
        rep(j, 1, h - 1)
        {
            if (a[j][i] == '#')
            {
                b[0][i] = j;
                break;
            }
        }
    }
    bool flag1 = false;
    rep(i, 2, w - 1)
    {
        if (b[0][i] != b[0][i - 1])
        {
            ans++;
            flag1 = false;
        }
        else
        {
            if (!flag1)
            {
                ans++;
                flag1 = true;
            }
        }
    }
    rep(i, 1, w - 1)
    {
        for (int j = h - 1; j >= 1; j--)
        {
            if (a[j][i] == '#')
            {
                b[1][i] = j;
                break;
            }
        }
    }
    flag1 = false;
    rep(i, 2, w - 1)
    {
        if (b[1][i] != b[1][i - 1])
        {
            ans++;
            flag1 = false;
        }
        else
        {
            if (!flag1)
            {
                ans++;
                flag1 = true;
            }
        }
    }
    rep(i, 1, h - 1)
    {
        rep(j, 1, w - 1)
        {
            if (a[i][j] == '#')
            {
                b[2][i] = j;
                break;
            }
        }
    }
    flag1 = false;
    rep(i, 2, h - 1)
    {
        if (b[2][i] != b[2][i - 1])
        {
            ans++;
            flag1 = false;
        }
        else
        {
            if (!flag1)
            {
                ans++;
                flag1 = true;
            }
        }
    }
    rep(i, 1, h - 1)
    {
        for (int j = w - 1; j >= 1; j--)
        {
            if (a[i][j] == '#')
            {
                b[3][i] = j;
                break;
            }
        }
    }
    flag1 = false;
    rep(i, 2, h - 1)
    {
        if (b[3][i] != b[3][i - 1])
        {
            ans++;
            flag1 = false;
        }
        else
        {
            if (!flag1)
            {
                ans++;
                flag1 = true;
            }
        }
    }
    cout << ans;
    return 0;
}