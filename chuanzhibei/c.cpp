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
bool judge(int a)
{
    int x;
    while (a > 0)
    {
        x = a % 10;
        if (x == 0)
            return false;
        a /= 10;
    }
    return true;
}
int main()
{
    FastIO;
    int n, k;
    cin >> n >> k;
    int num = 0;
    int x = 6;
    rep(i, 0, n - 1)
    {
        x = x * 10 + 6;
    }
    while (k * num <= x)
    {
        if (judge(k * num))
            num++;
    }
    cout << judge(10);
    cout << judge(0);
    cout << judge(11);
    //cout << x / k % MOD << endl;
    cout << (num - 1) % MOD << endl;
    return 0;
}