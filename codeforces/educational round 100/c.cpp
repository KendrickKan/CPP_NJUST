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
pii a[100005];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> km;
        mem0(a);
        rep(i, 0, n)
        {
            pii temp;
            cin >> temp.first >> temp.second;
            a[i] = temp;
            km.insert(temp);
        }
        int time = 0;
        int ans = 0;
        int loc = 0;
        rep(i, 0, n)
        {
            if (time <= a[i].first)
            {
                time = a[i].first + 1;
                int k = 0;
                while (k < a[i].second)
                {
                    //time++;
                    if (km.find(time)->second == loc)
                        ans++;
                    if (loc < a[i].second)
                        loc++;
                    else if (loc > a[i].second)
                        loc--;
                    time++;
                    k++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}