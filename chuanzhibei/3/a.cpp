//ctrl alt i new-head
#include <bits/stdc++.h>
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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct kpeople
{
    int x, y;
    int loc;
};
kpeople a[1000005];
bool cmp(kpeople a, kpeople b)
{
    if (a.x * a.y != b.x * b.y)
        return a.x * a.y > b.x * b.y;
    else if (a.x != b.x)
    {
        return a.x > b.x;
    }
    else
        return a.loc < b.loc;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    rep(i, 0, n)
    {
        int x, y;
        cin >> a[i].x >> a[i].y;
        a[i].loc = i + 1;
    }
    sort(a, a + n, cmp);
    rep(i, 0, n)
    {
        cout << a[i].loc << " ";
    }

    return 0;
}