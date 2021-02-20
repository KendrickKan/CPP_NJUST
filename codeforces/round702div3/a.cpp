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
    read(t);
    while (t--)
    {
        int n;
        read(n);
        vector<int> vec;
        rep(i, 0, n)
        {
            int temp;
            read(temp);
            vec.pb(temp);
        }
        int ans = 0;
        rep(i, 1, n)
        {
            int a, b;
            a = min(vec[i - 1], vec[i]);
            b = max(vec[i - 1], vec[i]);
            int n = 0;
            while (b > 2 * a)
            {
                n++;
                a *= 2;
            }
            ans += n;
        }
        cout << ans << endl;
    }
    return 0;
}