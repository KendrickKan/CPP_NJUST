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
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, p, k;
        cin >> n >> p >> k;
        string str;
        cin >> str;
        int x, y;
        cin >> x >> y;
        ll ans = 100000000000000000;
        for (int i = 0; i < k; i++)
        {
            int gai = 0;
            for (int j = str.length() - i - 1; j >= p - 1; j -= k)
            {
                if (str[j] == '0')
                {
                    gai++;
                }
                int temp = gai * x;
                temp = temp + (j - p + 1) * y;
                if (temp < ans)
                    ans = temp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}