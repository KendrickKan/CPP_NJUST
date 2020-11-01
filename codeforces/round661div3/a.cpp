#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int a[55];
    while (t--)
    {
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, cmp);
        if (n == 1)
            cout << "YES" << endl;
        else
        {
            int flag = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (abs(a[i] - a[i + 1]) > 1)
                {
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << "YES" << endl;
        }
    }

    return 0;
}