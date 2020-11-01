#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y)
{
    ll z = y;
    while (x % y != 0)
    {
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;

    cin >> t;
    while (t--)
    {
        ll sum = 0;
        ll n, k;
        cin >> n >> k;
        for(ll i = 1; i <= n; i++)
            for(ll j = i+1; j <= n; j++)
        {
            ll temp = gcd(i+1,j+1);
            ll lcm = (((i+1)/temp)%k*(j+1)%k)%k;
            sum = (sum%k+lcm%k)%k;
        }
        cout<<sum<<endl;
    }
    return 0;
}