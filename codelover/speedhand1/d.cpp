/*
 * @Author: KendrickKan 
 * @Date: 2021-02-01 19:15:15 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-02-01 19:35:04
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
    ll n, k;
    cin >> n >> k;
    if (n > k * (k - 1))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int num = 0;
        for (int i = 1; i <= k; i++)
        {
            for (int j = i + 1; j <= k; j++)
            {
                cout << i << " " << j << endl;
                num++;
                if (num >= n)
                {
                    return 0;
                }
                cout << j << " " << i << endl;
                num++;
                if (num >= n)
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}