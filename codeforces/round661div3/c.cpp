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
    int a[55];
    int b[55];
    while (t--)
    {
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int num = a[n - 1] + a[n - 2];
        int ans = 0;
        int temp;
        for (num; num >= a[0] + a[1]; num--)
        {
            temp = 0;
            memset(b, 0, sizeof(b));
            for (int i = 0; i < n - 1; i++)
                for (int j = i + 1; j < n; j++)
                {
                    if (a[i] + a[j] == num && b[i] == 0 && b[j] == 0)
                    {
                        temp++;
                        b[i] = 1;
                        b[j] = 1;
                    }
                }
            if (temp > ans)
                ans = temp;
        }
        cout << ans << endl;
    }

    return 0;
}