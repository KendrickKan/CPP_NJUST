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
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main()
{
    FastIO;
    int x, y;
    float area;
    cin >> x >> y;
    area = 10000 * 1.0 / 2 - y*1.0*(100-x)/2-x*1.0*y-(100-x)*1.0*(100-y)/2;
   // area = 10000 * 1.0 / 2 - 100 * 1.0 / 2 * (100 - x + y);
    cout << area;

    return 0;
}