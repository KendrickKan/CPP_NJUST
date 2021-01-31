/*
 * @Author: KendrickKan 
 * @Date: 2021-01-30 18:49:52 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-01-30 20:44:50
 */
#include <bits/stdc++.h>
using namespace std;
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
template <typename T>
void read(T &t)
{
    t = 0;
    char ch = getchar();
    int f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    do
    {
        (t *= 10) += ch - '0';
        ch = getchar();
    } while ('0' <= ch && ch <= '9');
    t *= f;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool vis[1000006];
int main()
{
    FastIO;
    int t;
    read(t);
    while (t--)
    {
        int n;
        read(n);
        int a[2005];
        rep(i, 0, 2 * n)
        {
            read(a[i]);
        }
        sort(a, a + 2 * n);
        bool flag = false;
        mem0(vis);
        for (int i = 2 * n - 2; i >= 0; i--)
        {
            int maxnum = a[2 * n - 1] + a[i];
            if (vis[a[i]])
                continue;
            vis[a[i]] = 1;
            multiset<int> s(a, a + 2 * n);
            vector<pii> ans;
            s.erase(s.find(a[2 * n - 1]));
            s.erase(s.find(a[i]));
            ans.push_back({a[2 * n - 1], a[i]});
            maxnum = a[2 * n - 1];
            while (s.size())
            {
                auto ttt = s.end();
                ttt--;
                int mx = *ttt;
                s.erase(ttt);
                if (s.find(maxnum - mx) == s.end())
                    break;
                ans.push_back({mx, maxnum - mx});
                s.erase(s.find(maxnum - mx));
                maxnum = mx;
            }
            if (ans.size() == n)
            {
                flag = true;
                cout << "YES" << endl;
                cout << ans[0].first + ans[0].second << endl;
                for (int q = 0; q < n; q++)
                {
                    cout << ans[q].first << " " << ans[q].second << endl;
                }
                break;
            }
        }
        if (!flag)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}