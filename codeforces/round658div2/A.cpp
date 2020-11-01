#include <bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int main()
{
    ios::sync_with_stdio(false);
    int t, n, m;
    cin >> t;
    while (t--)
    {
        int flag = 0;
        int num;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (a[i] == b[j])
                {
                    flag = 1;
                    num = a[i];
                    goto stop;
                }
            }
    stop:
        if (flag == 1)
        {
            cout << "YES" << endl;
            cout << '1' << ' ' << num << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}