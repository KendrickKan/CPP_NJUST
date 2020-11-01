/*
 * @Author: KendrickKan 
 * @Date: 2020-10-05 00:57:09 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-10-05 01:51:15
 */
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
bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int x[101][101];
        mem(x);
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                cin >> x[i][j];
            }
        }
        ll cnt = 0;
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                int a, b, c, d;
                if (i != (n - i - 1) && j != (m - j - 1))
                {
                    a = x[i][j];
                    b = x[i][m - j - 1];
                    c = x[n - i - 1][j];
                    d = x[n - i - 1][m - j - 1];
                    if (a != b || a != c || a != d)
                    {
                        int temp[4];
                        temp[0] = a;
                        temp[1] = b;
                        temp[2] = c;
                        temp[3] = d;
                        sort(temp, temp + 4, cmp);
                        int cnttemp = temp[1];
                        cnt += abs(temp[0] - temp[1]) + abs(temp[2] - temp[1]) + abs(temp[3] - temp[1]);
                        x[i][j] = x[i][m - j - 1] = x[n - i - 1][j] = x[n - i - 1][m - j - 1] = cnttemp;
                    }
                }
                else if (i != (n - i - 1) && j == (m - j - 1))
                {
                    int a, b;
                    a = x[i][j];
                    b = x[n - i - 1][j];
                    cnt += abs(a - b);
                    x[i][j] = x[i][m - j - 1] = x[n - i - 1][j] = x[n - i - 1][m - j - 1] = a;
                }
                else if (i == (n - i - 1) && j != (m - j - 1))
                {
                    int a, b;
                    a = x[i][j];
                    b = x[i][m - j - 1];
                    cnt += abs(a - b);
                    x[i][j] = x[i][m - j - 1] = x[n - i - 1][j] = x[n - i - 1][m - j - 1] = a;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}