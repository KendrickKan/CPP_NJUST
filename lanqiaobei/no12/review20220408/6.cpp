#include <iostream>
using namespace std;
int dp[105][100005];
int main()
{
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < 100005; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = 1;
                dp[i][j + x] = 1;
                dp[i][abs(j - x)] = 1;
                // dp[i][abs(x - j)] = 1;
            }
        }
    }
    int ans = 0;
    for (int j = 1; j < 100005; j++)
    {
        if (dp[n][j])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
