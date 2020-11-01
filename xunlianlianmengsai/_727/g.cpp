#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        cout << n << ' ' << p << endl;
        if (n == 1)
            cout << p << endl;
        else
        {
            cout << p + (n - 1) * (p - 2) << endl;
        }
    }

    return 0;
}