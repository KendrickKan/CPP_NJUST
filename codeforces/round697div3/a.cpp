/*
 * @Author: KendrickKan 
 * @Date: 2021-01-28 20:18:03 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-01-28 20:23:50
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
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        while (n % 2 == 0)
        {
            n /= 2;
        }
        if (n != 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}