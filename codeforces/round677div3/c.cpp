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
        int n;
        cin >> n;
        int a[300005];
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        int loc = 1;
        int kmaxnum = a[0];
        rep(i, 1, n)
        {
            if (a[i] > kmaxnum)
            {
                kmaxnum = a[i];
            }
        }
        rep(i, 0, n)
        {
            if (i == 0)
            {
                if (a[i] == kmaxnum && (a[i] > a[i + 1]))
                {

                    loc = i + 1;
                    break;
                }
            }
            else if (i < n - 1)
            {
                if (a[i] == kmaxnum && (a[i] > a[i - 1] || a[i] > a[i + 1]))
                {
                    loc = i + 1;
                    break;
                }
            }
            else
            {
                if (a[i] == kmaxnum && (a[i] > a[i - 1]))
                {
                    loc = i + 1;
                    break;
                }
            }
        }
        sort(a, a + n);
        if (a[0] == a[n - 1])
        {
            cout << -1 << endl;
        }
        else
        {
            cout << loc << endl;
        }
    }
    return 0;
}