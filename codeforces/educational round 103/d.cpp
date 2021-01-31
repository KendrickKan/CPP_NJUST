/*
 * @Author: KendrickKan 
 * @Date: 2021-01-30 16:08:11 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-01-30 16:26:53
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
int dl[300005];
int dr[300005];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        dl[0] = 1;
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] == str[i - 1])
                dl[i] = 1;
            else
                dl[i] = dl[i - 1] + 1;
        }
        dr[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (str[i] == str[i + 1])
                dr[i] = 1;
            else
                dr[i] = dr[i + 1] + 1;
        }
        repp(i, 0, n)
        {
            int ans = 1;
            if (i != 0)
                ans += str[i - 1] == 'L' ? dl[i - 1] : 0;
            if (i != n)
                ans += str[i] == 'R' ? dr[i] : 0;
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}