#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        ll x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        if (gcd(abs(x1), abs(y1)) == gcd(abs(x2), abs(y2)))
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}