/*
 * @Author: KendrickKan 
 * @Date: 2020-10-23 21:17:58 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-10-23 21:19:37
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
int jiecheng(int a)
{
    int sum = 1;
    rep(i, 2, a + 1)
    {
        sum *= i;
    }
    return sum;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    int ans = 0;
    rep(i, 1, n + 1)
    {
        ans += jiecheng(i);
    }
    cout << ans;
    return 0;
}