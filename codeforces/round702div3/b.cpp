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
int a[3];
bool check()
{
    if (a[0] == a[1] && a[1] == a[2])
        return true;
    else
        return false;
}
int main()
{
    FastIO;
    int t;
    read(t);
    while (t--)
    {
        int n;
        read(n);
        mem0(a);
        rep(i, 0, n)
        {
            int temp;
            read(temp);
            a[temp % 3]++;
        }
        int ans = 0;
        int i = 1;
        while (!check())
        {
            if (a[i % 3] < n / 3)
            {
                int temp = n / 3 - a[i % 3];
                ans += temp;
                a[i % 3] = n / 3;
                a[(i - 1) % 3] -= temp;
            }
            else if (a[i % 3] > n / 3)
            {
                int temp = a[i % 3] - n / 3;
                ans += temp;
                a[i % 3] = n / 3;
                a[(i + 1) % 3] += temp;
            }
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}