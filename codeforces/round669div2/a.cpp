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
    while (t--)
    {
        int n;
        cin >> n;
        int a[1005];
        memset(a, 0, sizeof(a));
        int sum0, sum1;
        sum0 = sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
                sum0++;
            else
                sum1++;
        }
        if (sum0 >= (n / 2))
        {
            cout << n / 2 << endl;
            for (int i = 0; i < n / 2; i++)
                cout << 0 << ' ';
        }
        else
        {
            if ((n / 2) % 2 == 0)
            {
                cout << n / 2 << endl;
                for (int i = 0; i < n / 2; i++)
                    cout << 1 << ' ';
            }
            else
            {
                if (sum1 > (n / 2))
                {
                    cout << n / 2 + 1 << endl;
                    for (int i = 0; i <= n / 2; i++)
                        cout << 1 << ' ';
                }
                else
                {
                    cout << n / 2 << endl;
                    for (int i = 0; i < n / 2 - 1; i++)
                        cout << 1 << ' ';
                    cout << 0;
                }
            }
        }
        cout << endl;
    }

    return 0;
}