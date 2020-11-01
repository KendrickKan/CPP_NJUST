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
        ll a;
        cin >> a;
        if (a > 30)
        {
            if (a == 36)
            {
                cout << "YES" << endl;
                cout << 15 << ' ' << 6 << ' ' << 10 << ' ' << 5 << endl;
            }
            else if (a == 40)
            {
                cout << "YES" << endl;
                cout << 6 << ' ' << 14 << ' ' << 15 << ' ' << 5 << endl;
            }
            else if (a == 44)
            {
                cout << "YES" << endl;
                cout << 6 << ' ' << 21 << ' ' << 10 << ' ' << 7 << endl;
            }
            else
            {
                cout << "YES" << endl;

                cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << a - 30 << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}