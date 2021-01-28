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
        string str;
        cin >> str;
        int ans = 0;
        if (str.length() == 1)
        {
            cout << 0 << endl;
        }
        else if (str.length() == 2)
        {
            if (str[0] == str[1])
            {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
            {
                if ((str[i] == str[i + 1] && str[i + 1] == str[i + 2]) && (i + 2) < str.length())
                {
                    ans += 2;
                    i += 2;
                }
                else
                {
                    if ((str[i] == str[i + 1]) && ((i + 1) < str.length()))
                    {
                        i++;
                        ans++;
                    }
                    else if (str[i] == str[i + 2] && ((i + 2) < str.length()))
                    {
                        ans++;
                        i += 2;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}