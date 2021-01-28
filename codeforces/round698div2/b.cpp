/*
 * @Author: KendrickKan 
 * @Date: 2021-01-28 22:44:35 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-01-28 23:31:18
 */
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
        int q, d;
        cin >> q >> d;
        rep(i, 0, q)
        {
            int x;
            cin >> x;
            if (x >= d * 10)
            {
                cout << "YES" << endl;
            }
            else
            {
                bool flag = false;
                for (int i = 1; i <= 9; i++)
                {
                    if (x % 10 == i * d % 10)
                    {
                        if (x < i * d)
                        {
                            cout << "NO" << endl;
                        }
                        else
                            cout << "YES" << endl;
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}