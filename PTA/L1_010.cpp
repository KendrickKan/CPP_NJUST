//ctrl alt i new-head
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define EPS 1e-10
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool cmp(ll a, ll b)
{
    return a < b;
}
int main()
{
    FastIO;
    ll a[3];
    cin >> a[0];
    cin >> a[1];
    cin >> a[2];
    sort(a, a + 3, cmp);
    cout << a[0] << "->" << a[1] << "->" << a[2];
    return 0;
}