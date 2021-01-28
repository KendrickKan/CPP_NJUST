//ctrl alt i new-head
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
int n, m;
vector<ll> a;
vector<ll> b;
// ll a[100005];
// ll b[100005];
ll Get_gcd(int temp)
{
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; i++)
    {
        q.push(a[i] + b[temp]);
    }
    ll mx_gcd = 1; //最大公约数
    while (1)
    {
        int flag = 1;
        priority_queue<ll, vector<ll>, greater<ll>> p;
        while ((!q.empty()) && (!q.top()))
        {
            q.pop();
        }
        if (q.empty())
            break;
        ll minc = q.top();
        q.pop();
        p.push(minc);
        while (!q.empty())
        {
            ll t = q.top();
            q.pop();
            t %= minc;
            if (t != 0)
                flag = 0;
            p.push(t);
        }
        if (flag)
        {
            mx_gcd = minc;
            break;
        }
        q = p;
    }
    return mx_gcd;
}
int main()
{
    FastIO;
    cin >> n >> m;
    rep(i, 0, n)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
        //cin >> a[i];
    }
    rep(i, 0, m)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    rep(i, 0, m)
    {
        cout << Get_gcd(i) << " ";
    }
    return 0;
}