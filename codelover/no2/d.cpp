/*
 * @Author: KendrickKan 
 * @Date: 2021-02-02 20:24:42 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-02-02 20:36:14
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
    ll a, b;
    cin >> a >> b;
    int x = 0, y = 1, z = 2;
    int m[7][3] = {
        {x, y, z},
        {y, x, z},
        {y, z, x},
        {z, y, x},
        {z, x, y},
        {x, z, y},
    };
    //cout << a % 6 << endl;
    cout << m[a % 6][b] << endl;
    return 0;
}