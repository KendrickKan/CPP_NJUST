#include <bits/stdc++.h>
using namespace std;
const int N = 7;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int a[N];
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        int num = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i];
            num += a[i];
        }
        int week = (n - 1) / num;
        int ans = N;
        for (int i = 0; i < N; ++i)
        {
            int x = n - week * num;
            for (int j = 1; j <= N; ++j)
            {
                if (a[(i + j) % N])
                {
                    x--;
                    if (!x)
                    {
                        ans = min(ans, j);
                        break;
                    }
                }
            }
        }
        cout << week * N + ans << endl;
    }
    return 0;
}
