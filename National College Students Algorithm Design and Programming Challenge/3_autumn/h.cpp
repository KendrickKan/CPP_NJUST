#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fo(x) for (register int i = 1; i <= x; ++i)
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
//const int MAXN = 2e5 + 5;
const int MAXN = 6;
ll kcount[MAXN];
pair<int, vector<int>> a[MAXN];
int b[MAXN];
int main()
{
    FastIO;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        a[y].first = x;
        //a[x].second.push_back(y); //将他加入他父亲
        b[x] = 1; //不是叶子节点
    }
    for (int i = 0; i <= n; i++)
    {
        //将能影响到叶子节点的父辈都加入叶子节点同时也将叶子节点添加到父辈
        if (b[i] == 0)
        {
            a[i].second.push_back(i);
            int x = a[i].first;
            a[i].second.push_back(x);
            a[x].second.push_back(i);
            while (a[x].first != 0)
            {
                x = a[x].first;
                a[i].second.push_back(x);
                a[x].second.push_back(i);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int method;
        cin >> method;
        if (method == 1)
        {
            int x, y;
            cin >> x >> y;
            kcount[x] += y;
            if (b[x] != 0)
            {
                for (int i = 0; i < a[x].second.size(); i++)
                {
                    kcount[a[x].second[i]] += y;
                }
            }
        }
        if (method == 2)
        {
            int x;
            cin >> x;
            ll maxans = -1;
            for (int i = 0; i < a[x].second.size(); i++)
            {
                maxans = max(maxans, kcount[a[x].second[i]]);
            }
            // int y = a[x].first;
            // maxans += kcount[y];
            // while (a[y].first != 0)
            // {
            //     y = a[y].first;
            //     maxans += kcount[y];
            // }
            cout << maxans << endl;
        }
    }
    //cout << 1;
    return 0;
}