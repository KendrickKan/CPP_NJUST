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
        int n, k;
        cin >> n >> k;
        int midnum = 0;
        int x;
        int y;
        rep(i, 0, n)
        {
            cin >> x;
            if (x == (k / 2) && k % 2 == 0)
            {
                y = midnum % 2;
                midnum++;
            }
            else if (x * 2 < k)
                y = 0;
            else
                y = 1;
            cout << y << ' ';
        }
        cout << endl;
    }
    return 0;
}