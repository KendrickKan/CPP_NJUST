#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int a[N], dp[N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, ans;
    while (cin >> n)
    {
        ans = 2;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = 2;
            }
        }
        int j, k;
        for (int i = 0; i < n; i++)
        {
            j = i - 1;
            k = i + 1;
            while (j >= 0 && k < n)
            {
                if (a[j] + a[k] == 2 * a[i])
                {
                    dp[i][k] = dp[j][i] + 1;
                    ans = max(ans, dp[i][k]);
                    j--;
                    k++;
                }
                else
                {
                    if (a[j] + a[k] < 2 * a[i])
                    {
                        k++;
                    }
                    else
                    {
                        j--;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}