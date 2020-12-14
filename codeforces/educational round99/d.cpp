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
int a[505];
int b[505];
bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        mem0(a);
        int n, x;
        cin >> n >> x;
        int minn = 555;
        rep(i, 0, n)
        {
            cin >> a[i];
            b[i] = a[i];
            minn = min(minn, a[i]);
        }
        a[n] = x;
        sort(a, a + n + 1, cmp);
        if (x >= minn)
        {
            bool flag = false;
            for (int i = 0; i < n - 1; i++)
            {
                if (b[i] > b[i + 1])
                    flag = true;
                break;
            }
            if (flag)
                cout << -1 << endl;
            else
                cout << 0 << endl;
        }
        else
        {
            int num = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != b[i])
                    num++;
            }
            int num2 = 0;
            for (int i = n; i >= 0; i--)
            {
                if (a[i] != a[n])
                {
                    a[i] = 555;
                    break;
                }
            }
            sort(a, a + n + 1, cmp);
            for (int i = 0; i < n; i++)
            {
                if (a[i] != b[i])
                    num2++;
            }
            cout << min(num, num2) << endl;
        }
    }
    return 0;
}