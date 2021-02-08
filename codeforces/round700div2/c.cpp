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
const int maxn = 100005;
int n;
int a[maxn];
void find(int x)
{
    if (x >= 1 && x <= n)
    {
        cout << "? " << x << endl;
        fflush(stdout);
        cin >> a[x];
    }
}
int main()
{
    FastIO;
    cin >> n;
    a[0] = a[n + 1] = n + 1000;
    int L = 1, R = n;
    while (L < R)
    {
        int mid = (L + R) / 2;
        find(mid);
        find(mid + 1);
        if (a[mid] < a[mid + 1])
            R = mid;
        else
            L = mid + 1;
    }
    cout << "! " << R << endl;
    fflush(stdout);
    return 0;
}