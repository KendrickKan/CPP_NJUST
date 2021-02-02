/*
 * @Author: KendrickKan 
 * @Date: 2021-02-02 19:33:34 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-02-02 19:53:01
 */
#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    FastIO;
    int n;
    cin >> n;
    int a[50][50];
    memset(a, 0, sizeof(a));
    int cnt = 1;
    int x = 0, y = n / 2;
    a[x][y] = cnt;
    cnt++;
    while (cnt <= n * n)
    {
        if (x == 0 && y < n - 1)
        {
            x = n - 1;
            y += 1;
            a[x][y] = cnt;
        }
        else if (x != 0 && y == n - 1)
        {
            x -= 1;
            y = 0;
            a[x][y] = cnt;
        }
        else if (x == 0 && y == n - 1)
        {
            x += 1;
            a[x][y] = cnt;
        }
        else if (x != 0 && y != n - 1)
        {
            if (!a[x - 1][y + 1])
            {
                x -= 1;
                y += 1;
            }
            else
                x += 1;
            a[x][y] = cnt;
        }
        cnt++;
    }
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}