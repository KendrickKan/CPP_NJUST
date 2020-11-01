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
        int a[55];
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        cin >> a[0];
        int temp = a[0];
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
        }
        bool flag = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == temp)
            {
                flag = 1;
                break;
            }
            else
                temp = a[i];
        }
        if (flag == 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}