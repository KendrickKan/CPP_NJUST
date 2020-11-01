#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        if (x <= n && y == 1)
        {
            for (int i = 1; i <= x - 1; ++i)
                cout << i << " ";
            for (int i = x + 1; i <= n; ++i)
                cout << i << " ";
            cout << n + 1;
        }
        else if (x > n && y == 1)
        {
            for (int i = 1; i <= n - 1; ++i)
                cout << i << " ";
            cout << n;
        }
        else if (x <= n && y == 2)
        {
            for (int i = 1; i <= n - 1; ++i)
                cout << i << " ";
            cout << n;
        }
        else if (x > n && y == 2)
        {
            for (int i = 1; i <= n - 1; ++i)
                cout << i << " ";
            cout << x;
        }
        cout << endl;
    }
    return 0;
}