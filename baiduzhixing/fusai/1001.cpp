#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll m;
        int p, q;
        cin >> m >> p >> q;
        int x = abs((p * (100 - q) - q * (100 - p)) * m + p * 100);
        if (x < 10000)
        {
            int a;
            for (int i = x; i > 0; i--)
                if ((x % i == 0) && (10000 % i == 0))
                {
                    a = i;
                    break;
                }
            x /= a;
            int y = 10000;
            y /= a;
            if (MOD % y == 0)
                cout << MOD / y << endl;
            else
                cout << MOD / y + 1 << endl;
        }
        else
        {
            int a;
            for (int i = 10000; i > 0; i--)
                if ((x % i == 0) && (10000 % i == 0))
                {
                    a = i;
                    break;
                }
            x /= a;
            int y = 10000;
            y /= a;
            cout << x / y % MOD << endl;
        }
    }

    return 0;
}