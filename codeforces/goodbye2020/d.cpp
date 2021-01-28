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
struct node
{
    int loc;
    int weight;
    bool ifjudge;
    vector<node> vec;
};
bool cmploc(node a, node b)
{
    return a.loc < b.loc;
}
bool cmpwei(node a, node b)
{
    return a.weight > b.weight;
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
        vector<node> kvec;
        vector<node> rem;
        ll ans = 0;
        rep(i, 0, n)
        {
            int x;
            cin >> x;
            node temp;
            temp.loc = i + 1;
            temp.weight = x;
            temp.ifjudge = false;
            ans += x;
            kvec.push_back(temp);
            rem.push_back(temp);
        }
        rep(i, 0, n - 1)
        {
            int x, y;
            cin >> x >> y;
            node temp;
            temp.loc = kvec[x - 1].loc;
            temp.weight = kvec[x - 1].weight;
            kvec[y - 1].vec.push_back(temp);
            temp.loc = kvec[y - 1].loc;
            temp.weight = kvec[y - 1].weight;
            kvec[x - 1].vec.push_back(temp);
        }
        sort(kvec.begin(), kvec.end(), cmpwei);
        cout << ans << " ";
        rep(i, 0, n - 1)
        {
            if (rem[i].ifjudge == false)
            {
                sort(kvec[i].vec.begin(), kvec[i].vec.end(), cmpwei);
                for (int j = 0; j < kvec[i].vec.size(); j++)
                {
                    if (rem[kvec[i].vec[j].loc - 1].ifjudge == false)
                    {
                        ans += max(kvec[i].vec[j].weight, kvec[i].weight);
                        cout << ans << " ";
                        int tt = kvec[i].vec[j].loc;
                        rem[kvec[i].vec[j].loc - 1].ifjudge = true;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}