#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x = n % 4;
        int y = n / 4;
        if (x != 0)
        {
            for (int i = 0; i < n - y - 1; i++)
                cout << 9;
            for (int i = n - y - 1; i < n; i++)
                cout << 8;
        }
        else
        {
            for (int i = 0; i < n - y; i++)
                cout << 9;
            for (int i = n - y; i < n; i++)
                cout << 8;
        }
        cout << endl;
    }

    return 0;
}