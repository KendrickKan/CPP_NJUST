#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
int r[MAXN];
int dp[MAXN][MAXN];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n + 1; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for (int d = 1; d <= n - 1; d++)
    {
        for (int i = 1; i <= n - d; i++)
        {
            int j = i + d;
            dp[i][j] = 1e9 + 7;
            for (int k = i + 1; k <= j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j] + r[i] * r[k] * r[j + 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
}