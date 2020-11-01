/*
 * @Author: KendrickKan 
 * @Date: 2020-10-23 21:08:51 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-10-23 21:13:32
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
    ll sum=0, start;
    ll n;
    cin >> n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;
        ll j = i;
        ll t = n;          
        ll maxnum = 0;       
        while (t % j == 0)
        {
            t /= j;
            maxnum++;
            j++;
        }
        if (sum < maxnum)
        {
            sum = maxnum;
            start = i;
        }
    }
    if (sum == 0)
        cout << "1" << endl
             << n << endl;
    else
    {
        cout << sum << endl;
        for (int i = 0; i < sum; i++)
        {
            if (i == sum - 1)
                cout << start + i << endl;
            else
                cout << start + i << "*";
        }
    }

    return 0;
}