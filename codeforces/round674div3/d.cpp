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
    int n;
    cin >> n;
    int a[200005];
    int qianzhuihe[200005];
    mem(qianzhuihe);
    mem(a);
    ll x = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        qianzhuihe[i] = x + a[i];
        x = qianzhuihe[i];
    }
    sort(qianzhuihe, qianzhuihe + n);
    int cnt = 0;
    ll temp = qianzhuihe[0];
    rep(i, 1, n)
    {
        if (qianzhuihe[i] == temp)
            cnt++;
        else
        {
            temp = qianzhuihe[i];
        }
    }
    cout << cnt;
    return 0;
}