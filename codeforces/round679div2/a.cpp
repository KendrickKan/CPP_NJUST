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
struct kkk
{
    int benshen;
    int yaocheng;
    int loc;
};
bool cmp1(kkk a, kkk b)
{
    return a.benshen < b.benshen;
}
bool cmp2(kkk a, kkk b)
{
    return a.loc < b.loc;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        kkk a[105];
        rep(i, 0, n)
        {
            cin >> a[i].benshen;
            a[i].loc = i;
        }
        sort(a, a + n, cmp1);
        rep(i, 0, n / 2)
        {
            a[i].yaocheng = a[n - 1 - i].benshen;
            a[n - 1 - i].yaocheng = a[i].benshen * (-1);
        }
        sort(a, a + n, cmp2);
        rep(i, 0, n)
        {
            cout << a[i].yaocheng << " ";
        }
        if (t)
            cout << endl;
    }
    return 0;
}