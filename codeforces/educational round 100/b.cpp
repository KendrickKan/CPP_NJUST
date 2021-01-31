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
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int a[55];
        mem0(a);
        int n;
        cin >> n;
        ll ans = 0;
        int maxnum = -1;
        int minnum = 2000000000;
        rep(i, 0, n)
        {
            cin >> a[i];
            minnum = min(minnum, a[i]);
            maxnum = max(maxnum, a[i]);
            ans += a[i];
        }
        rep(j, minnum, maxnum + 1)
        {
            int c[55];
            ll tempans = 0;
            int temp = j;
            c[0] = temp;
            tempans = abs(temp - a[0]);
            //cout << a[j] << " ";
            rep(i, 1, n)
            {
                if (a[i] % temp == 0 || temp % a[i] == 0)
                {
                    c[i] = a[i];
                    // cout << a[i] << " ";
                    temp = a[i];
                }
                else
                {
                    int newtemp;
                    if (a[i] / temp == 0)
                        newtemp = temp;
                    else
                    {
                        if ((a[i] - a[i] / temp) > temp / 2)
                            newtemp = (temp * (a[i] / temp));
                        else
                            newtemp = (temp * (a[i] / temp + 1));
                    }
                    tempans = abs(newtemp - a[i]);
                    c[i] = newtemp;
                    //cout << newtemp << " ";
                    temp = newtemp;
                }
                //cout << ans / n << " ";
            }
            if (tempans * 2 <= ans)
            {
                rep(x, 0, n)
                {
                    cout << c[x] << " ";
                }
                break;
            }
        }
        cout << endl;
    }
    return 0;
}