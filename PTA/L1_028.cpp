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
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool ifprime(ll t)
{
    for (int i = 2; i < sqrt(t); i++)
    {
        if (t % i == 0)
            return false;
    }
    return true;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    while (n--)
    {
        ll t;
        cin >> t;
        if (ifprime(t))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}