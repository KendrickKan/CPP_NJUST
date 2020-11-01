/*
 * @Author: KendrickKan 
 * @Date: 2020-10-05 00:16:39 
 * @Last Modified by:   KendrickKan 
 * @Last Modified time: 2020-10-05 00:16:39 
 */
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
        ll a, b, c;
        cin >> a >> b >> c;
        ll x[3];
        x[0] = a;
        x[1] = b;
        x[2] = c;
        ll max = a + b + c;
        sort(x, x + 3);
        cout << max-1 << endl;
    }
    return 0;
}