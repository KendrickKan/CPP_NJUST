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
        int a[55][55];
        int b[3][3];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        int cnt = 0;
        int x, y;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                cin >> b[i][j];
                if (b[i][j])
                {
                    cnt++;
                    x = i;
                    y = j;
                }
            }
        if (cnt > 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                    cout << 0 << ' ';
                cout << 0;
                cout << endl;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i + x < n && j + y < n)
                        a[i][j] = a[i + x][j + y];
                    else
                    {
                        a[i][j] = 0;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                    cout << a[i][j] << ' ';
                cout << a[i][n - 1];
                cout << endl;
            }
        }
    }
    return 0;
}