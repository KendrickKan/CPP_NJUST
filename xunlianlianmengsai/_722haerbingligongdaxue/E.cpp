#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (a[0] == x && a[n - 1] == y)
            cout << "BOTH" << endl;
        else if (a[0] == x && a[n - 1] != y)
            cout << "EASY" << endl;
        else if (a[0] != x && a[n - 1] == y)
            cout << "HARD" << endl;
        else
        {
            cout << "OKAY" << endl;
        }
    }

    return 0;
}