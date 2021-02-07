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
        int a, b, n;
        cin >> a >> b >> n;
        ll he = 0;
        bool flag = false;
        ll maxnum = 0;
        ll maxt, maxh;
        vector<int> ta;
        vector<int> hel;
        rep(i, 0, n)
        {
            int x;
            cin >> x;
            ta.push_back(x);
        }
        rep(i, 0, n)
        {
            int x;
            cin >> x;
            hel.push_back(x);
        }
        rep(i, 0, n)
        {
            int x, y;
            x = ta[i];
            y = hel[i];
            ll temp;
            temp = ceil(y * 1.0 / a) * x;
            //b -= temp;
            he += temp;
            if (x > maxnum)
            {
                maxnum = x;
                maxt = x;
                maxh = y;
            }
        }
        if (he <= b)
        {
            cout << "YES" << endl;
        }
        else
        {
            if ((he - maxnum) < b)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
            // ll temp = ceil(maxh * 1.0 / a);
            // if (temp == 1)
            //     cout << "YES" << endl;
            // else
            // {
            //     he -= maxt;
            //     if (he <= b)
            //         cout << "YES" << endl;
            //     else
            //         cout << "NO" << endl;
            // }
        }
        // if (flag)
        //     cout << "NO" << endl;
        // else
        //     cout << "YES" << endl;
    }
    return 0;
}