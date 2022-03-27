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
int a[100005];
bool CHECK(int a[], int n, int k, int max_value)
{
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > max_value) 
            return false;
        sum += a[i];
        if (sum > max_value)
        {
            cnt++;
            sum = a[i];
        }
    }
    cnt++;
    return cnt <= k;
}
int BinarySearch(int a[], int n, int k)
{
    int low = 0, high = INT_MAX;
    while (high > low)
    {
        int mid = (low + high) >> 1;
        if (CHECK(a, n, k, mid))
            high = mid;
        else
            low = mid + 1;
    }
    return high;
}
int main()
{
    FastIO;
    int n, k;
    cin >> n >> k;
    rep(i, 0, n)
    {
        cin >> a[i];
        a[i] = a[i] * a[i];
    }
    cout << BinarySearch(a, n, k) << endl;
    return 0;
}