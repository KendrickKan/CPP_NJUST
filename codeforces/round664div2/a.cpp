#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        int flag = 0;
    xyz:
        if ((a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && d % 2 == 0) || (b % 2 == 0 && c % 2 == 0 && d % 2 == 0) || (a % 2 == 0 && c % 2 == 0 && d % 2 == 0) || (a % 2 == 0 && b % 2 == 0 && d % 2 == 0) || (a % 2 == 0 && b % 2 == 0 && c % 2 == 0))
            cout << "Yes" << endl;
        else
        {
            if ((a == 0 || b == 0 || c == 0) || (a % 2 == 1 && b % 2 == 1 && c % 2 == 0 && d % 2 == 0) || (a % 2 == 1 && b % 2 == 0 && c % 2 == 1 && d % 2 == 0) || (a % 2 == 1 && b % 2 == 0 && c % 2 == 0 && d % 1 == 0) || (a % 2 == 0 && b % 2 == 1 && c % 2 == 1 && d % 2 == 0) || (a % 2 == 0 && b % 2 == 1 && c % 2 == 0 && d % 2 == 1) || (a % 2 == 0 && b % 2 == 0 && c % 2 == 1 && d % 2 == 1))
                cout << "No" << endl;
            else
            {
                a--;
                b--;
                c--;
                d += 3;
                goto xyz;
            }
        }
    }

    return 0;
}