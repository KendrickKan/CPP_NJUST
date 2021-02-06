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
bool heros[1005];
vector<int> peo[1005];
int main()
{
    FastIO;
    int m, n, k;
    cin >> m >> n >> k;
    rep(i, 0, m)
    {
        int x;
        cin >> x;
        heros[x] = 1;
    }
    rep(i, 0, k)
    {
        int p, h;
        cin >> p >> h;
        if (heros[h] == false)
            peo[p].push_back(h);
    }
    bool flag = true;
    repp(i, 1, m)
    {
        if (peo[i].size() == 0)
        {
            flag = false;
            break;
        }
    }
    // repp(i, 1, m)
    // {
    //     bool kvis[1005];
    //     rep(j, 0, 1005)
    //     {
    //         kvis[j] = heros[j];
    //     }
    // }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}