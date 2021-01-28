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
int a[100005];
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
        int n;
        cin >> n;
        mem0(a);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        int sum = 1;
        bool flag = false;
        a[n - 1]++;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i - 1] + 1 < a[i])
            {
                sum++;
                a[i - 1]++;
            }
            else
            {
                if (a[i - 1] + 1 == a[i])
                {
                    sum++;
                }
                else if (a[i - 1] != a[i])
                {
                    sum++;
                }
            }
        }
        // rep(i, 0, n)
        // {
        //     if (a[i] < a[i + 1] && flag == false)
        //     {
        //         sum++;
        //     }
        //     else if (a[i] < a[i + 1] && flag == true)
        //     {
        //         //if ((a[i] + 1) != a[i + 1])
        //         //{
        //         sum++;
        //         a[i + 1]++;
        //         //}
        //         flag = false;
        //     }
        //     else if (a[i] == a[i + 1] && flag == false)
        //     {
        //         sum++;
        //         flag = true;
        //     }
        // }
        cout << sum << endl;
    }
    return 0;
}