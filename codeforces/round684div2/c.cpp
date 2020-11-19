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
    int x;
    int y;
};
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int kmap[105][105];
        int n, m;
        cin >> n >> m;
        priority_queue<node> vec;
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                cin >> kmap[i][j];
                if (kmap[i][j] == 1)
                {
                    node t;
                    t.x = i + 1;
                    t.y = i + 1;
                    vec.push(t);
                }
            }
        }
    }
    return 0;
}