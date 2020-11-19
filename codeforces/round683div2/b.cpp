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
int a[15][15];
int n, m;
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        mem0(a);
        cin >> n >> m;
        int zheng, fu, ling;
        zheng = fu = ling = 0;
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                cin >> a[i][j];
                if (a[i][j] > 0)
                    zheng++;
                else if (a[i][j] < 0)
                    fu++;
                else
                    ling++;
            }
        }
        int ans = 0;
        if (fu % 2 == 0)
        {
            rep(i, 0, n)
            {
                rep(j, 0, m)
                {
                    ans += abs(a[i][j]);
                }
            }
        }
        else
        {
            if (ling > 0)
            {
                rep(i, 0, n)
                {
                    rep(j, 0, m)
                    {
                        ans += abs(a[i][j]);
                    }
                }
            }
            else
            {
                int minabs = 10000;
                rep(i, 0, n)
                {
                    rep(j, 0, m)
                    {
                        if (abs(a[i][j]) < minabs)
                            minabs = abs(a[i][j]);
                        ans += abs(a[i][j]);
                    }
                }
                ans -= 2 * minabs;
            }
        }
        cout << ans << endl;
    }

    return 0;
}