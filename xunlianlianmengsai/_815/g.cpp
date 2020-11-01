#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 1e6 + 50;
ll z[maxn] = {0};
ll y[maxn] = {0};
int n;
ll a[maxn];
ll num1[maxn];
ll num2[maxn];
ll lowbit(ll x)
{
    return x & (-x);
}
ll query(ll i, ll t[])
{
    ll ans = 0;
    while (i)
    {
        ans += t[i];
        i -= lowbit(i);
    }
    return ans;
}
void add(ll i, ll x, ll t[])
{
    while (i < maxn)
    {
        t[i] += x;
        i += lowbit(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = n - 1; i >= 0; --i)
    {
        num1[i] = query(maxn - a[i] - 1, y);
        add(maxn - a[i], 1, y);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        num2[i] = query(maxn - a[i] - 1, z);
        add(maxn - a[i], 1, z);
    }
    for (int i = 0; i < n; ++i)
        ans += min(num1[i], num2[i]);
    cout << ans << endl;
}