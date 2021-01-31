/*
 * @Author: KendrickKan 
 * @Date: 2021-01-29 23:26:14 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-01-30 15:52:38
 */
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
int a[100005];
int b[100005];
int c[100005];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        rep(i, 0, n)
        {
            cin >> b[i];
        }
        rep(i, 0, n)
        {
            cin >> c[i];
        }
        ll tempnum;
        ll maxnum = abs(b[1] - c[1]) + a[1] - 1 + 2;
        ll ans = 0;
        tempnum = maxnum;
        rep(i, 2, n)
        {
            if (c[i] != b[i])
            {
                tempnum += 2;
                tempnum += a[i] - 1;
                tempnum -= abs(c[i] - b[i]);
                ll ttt = abs(c[i] - b[i]) + a[i] - 1 + 2;
                tempnum = max(ttt, tempnum);
                if (maxnum < tempnum)
                    maxnum = tempnum;
            }
            else
            {
                if (maxnum < tempnum)
                {
                    maxnum = tempnum;
                }
                tempnum = 2 + a[i] - 1;
            }
            ans = max(max(maxnum, tempnum), ans);
        }
        ans = max(max(maxnum, tempnum), ans);
        cout << ans << endl;
    }
    return 0;
}