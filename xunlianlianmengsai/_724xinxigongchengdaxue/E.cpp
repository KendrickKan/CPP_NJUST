#include <bits/stdc++.h>

#define ll long long
#define pil pair<int, ll>
using namespace std;
const int N = 1e3 + 10;
const ll inf = 1e15;
vector<pil> List[N];
bool v[N][12];
int s, t;

struct node
{
    int i, j, x; //i第几首歌，x歌曲序号
    ll d;

    bool operator<(const node &a) const
    {
        return d > a.d;
    }
};

inline void read()
{
    cin >> t >> s;
    int n;
    for (int i = 1; i <= s; i++)
    {
        scanf("%d", &n);
        for (int j = 1; j <= n; j++)
        {
            ll x;
            scanf("%lld", &x);
            List[i].push_back({x, inf});
        }
    }
}

inline long long dis(long long i, long long j)
{
    long long res;
    if (i == j)
        res = 1;
    else if (i > j)
        res = min(i - j + 1, j + t - i - 1);
    else
        res = min(j - i - 1, i + t - j + 1);
    return res;
}

inline ll dijkstra()
{
    priority_queue<node> q;
    q.push({0, 0, t, 0});
    while (!q.empty())
    {
        node te = q.top();
        q.pop();
        if (te.i == s)
            return te.d;
        if (v[te.i][te.j])
            continue;
        v[te.i][te.j] = true;
        for (int i = 0; i < List[te.i + 1].size(); i++)
        {
            pil tc = List[te.i + 1][i];
            if (tc.second > te.d + dis(te.x, tc.first))
            {
                List[te.i + 1][i].second = te.d + dis(te.x, tc.first);
                q.push({te.i + 1, i, tc.first, List[te.i + 1][i].second});
            }
        }
    }
}

int main()
{
    read();
    cout << dijkstra() << endl;
    return 0;
}
