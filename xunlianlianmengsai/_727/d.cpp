#include <bits/stdc++.h>
using namespace std;
map<string, int> M;
int pre[505];
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        pre[i] = i;
    }
}
int find(int x)
{
    if (pre[x] == x)
        return x;
    else
        return pre[x] = find(pre[x]);
}
void merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx != fy)
        pre[fx] = fy;
}
int main()
{
    ios::sync_with_stdio(false);
    int m, t, n, e;
    cin >> m;
    while (m--)
    {
        M.clear();
        cin >> t;
        while (t--)
        {
            string s;
            cin >> s;
            M[s] = 1;
        }
        cin >> n >> e;
        init(n);
        while (e--)
        {
            int a, b;
            string tr;
            cin >> a >> b;
            cin >> tr;
            if (!M[tr])
                merge(a, b);
        }
        if (find(0) == find(n - 1))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}