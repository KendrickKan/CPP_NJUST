#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int findroot(int pre[], int x)
{
    int r = x;
    while (pre[r] != r)
    {
        r = pre[r];
    }
    int i = x;
    int j;
    while (i != r) //路径压缩
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int pre[1005];
    memset(pre, 0, sizeof(pre));
    int n, m, loca, locb, root1, root2;
    int totalroad;
    while (cin >> n && n)
    {
        memset(pre, 0, sizeof(pre));
        totalroad = n - 1;
        for (int i = 1; i <= n; i++)
            pre[i] = i;
        cin >> m;
        while (m--)
        {
            cin >> loca >> locb;
            root1 = findroot(pre, loca);
            root2 = findroot(pre, locb);
            if (root1 != root2) //并集
            {
                pre[root2] = root1;
                totalroad--;
            }
        }
        cout << totalroad << endl;
    }
    return 0;
}