#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;

using namespace std;

ll ans, maxn, n;

int max(int i, int j)
{
    return (i > j) ? i : j;
}

void find(ll x)
{
    ll l = x, r = x;
    ll dep = 0;
    while (l * 2 <= n)
    {
        l *= 2;
        dep++;
    }
    while (r * 2 + 1 <= n)
        r = r * 2 + 1;
    if (l <= r)
        maxn = max(maxn, dep);
    else
    {
        find(2 * x);
        find(2 * x + 1);
        ans++;
    }
}
int main()
{
    while (cin >> n)
    {
        ans = 0;
        maxn = 0;
        find(1);
        cout << ans + maxn + 1 << endl;
    }
    return 0;
}