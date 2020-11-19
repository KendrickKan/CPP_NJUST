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
struct node
{
    ll num;
    int loc;
};
bool cmp(node a, node b)
{
    return a.num < b.num;
}
bool cmp1(int a, int b)
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
        ll n, w;
        cin >> n >> w;
        vector<node> vec;
        rep(i, 0, n)
        {
            node p;
            ll temp;
            cin >> temp;
            // if (temp > w)
            //     continue;
            p.num = temp;
            p.loc = i + 1;
            vec.pb(p);
        }
        sort(vec.begin(), vec.end(), cmp);
        long long midnum = (w - 1) / 2 + 1;
        bool flag = false;
        ll ans = 0;
        vector<int> shuju;
        bool ifcan = false;
        rep(i, 0, n)
        {
            if (vec[i].num >= midnum && vec[i].num <= w)
            {
                ifcan = true;
                cout << 1 << endl
                     << vec[i].loc << endl;
                break;
            }
        }
        if (ifcan == false)
        {
            int ansnum = 0;
            rep(i, 0, n)
            {
                ansnum++;
                shuju.push_back(vec[i].loc);
                ans += vec[i].num;
                if (ans >= midnum && ans <= w)
                {
                    break;
                }
                else if (ans < midnum)
                    continue;
                else
                {
                    flag = true;
                }
            }
            if (ans < midnum || ans > w)
                flag = true;
            if (flag)
                cout << -1 << endl;
            else
            {
                sort(shuju.begin(), shuju.end(), cmp1);
                cout << ansnum << endl;
                rep(i, 0, ansnum)
                {
                    cout << shuju[i] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}