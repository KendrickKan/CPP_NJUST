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
bool cmp(int a, int b)
{
    return a < b;
}
bool judge(int a[], int n, int k)
{
    rep(i, 0, n)
    {
        if (a[i] > k)
            return false;
    }
    return true;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int a[1005];
        mem(a);
        int n, k;
        cin >> n >> k;
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        int cnt = 0;
        rep(i, 1, n)
        {
            cnt += (k - a[i]) / a[0];
        }
        cout<<cnt<<endl;
    }
    return 0;
}