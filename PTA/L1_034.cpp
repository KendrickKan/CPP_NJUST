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
    int xiabiao;
    int num;
};
node nod[1005];
bool cmp(node a, node b)
{
    if (a.num != b.num)
        return a.num > b.num;
    else
        return a.xiabiao > b.xiabiao;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    for (int i = 0; i < 1005; i++)
    {
        nod[i].xiabiao = i;
    }
    while (t--)
    {
        int n;
        cin >> n;
        while (n--)
        {
            int x;
            cin >> x;
            nod[x].num++;
        }
    }
    sort(nod, nod + 1005, cmp);
    cout << nod[0].xiabiao << " " << nod[0].num << endl;
    return 0;
}