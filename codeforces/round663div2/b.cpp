#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    char a[105][105];
    while (t--)
    {
        memset(a, 0, sizeof(a));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        int ans = 0;
        for (int i = 1; i < n; i++)
            if (a[i][m] != 'D')
                ans++;
        for (int i = 1; i < m; i++)
            if (a[n][i] != 'R')
                ans++;
        cout << ans << endl;
    }

    return 0;
}