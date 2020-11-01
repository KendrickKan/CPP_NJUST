#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int a[55][1005];
    int b[1005];
    while (cin >> n >> m && (n || m))
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                b[j] += a[i][j];
            }
        sort(b, b + n);
        cout << b[n - 1] << endl;
    }

    return 0;
}