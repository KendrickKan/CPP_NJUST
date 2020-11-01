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
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int a[55];
        mem(a);
        int n;
        cin >> n;
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        int ansleft = 0;
        int ansright = 0;
        int x, y;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == 1)
            {
                x = i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                y = i;
                break;
            }
        }
        for (int i = y; i < x; i++)
        {
            if (a[i] == 0)
            {
                ansleft++;
            }
        }
        cout << ansleft << endl;
    }
    return 0;
}