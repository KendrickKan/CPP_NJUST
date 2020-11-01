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
    int a, b;
    cin >> a >> b;
    int sum = 0;
    int cnt = 0;
    rep(i, a, b + 1)
    {
        cnt++;
        sum += i;
        cout << setw(5) << i;
        if (cnt % 5 == 0 && i != b)
            cout << endl;
    }
    cout << endl;
    cout << "Sum = " << sum;
    return 0;
}