/*
 * @Author: KendrickKan 
 * @Date: 2020-09-28 18:12:45 
 * @Last Modified by:   KendrickKan 
 * @Last Modified time: 2020-09-28 18:12:45 
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
#define eps 1e-10
#define mod 1e9 + 7
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
        ll x = 1;
        ll cnt = 0;
        while (x < n)
        {
            cnt++;
            if ((cnt + 2) % 2 == 0)
                x = (cnt + 2) * (cnt + 2) / 4;
            else
            {
                x = ((cnt + 2) / 2) * ((cnt + 2) - ((cnt + 2) / 2));
            }
        }
        cout << cnt << endl;
    }
    return 0;
}