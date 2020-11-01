#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GDC(ll a, ll b)
{
    return (b > 0) ? GDC(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(false);
    ll t;
    while (cin >> t)
        for (ll i = 1; i <= t; i++)
        {
            ll X, N, Y, M;
            cin >> X >> N >> Y >> M;
            ll num1, num2;
            num1 = X;
            num2 = 0;
            for (ll j = 1; j <= N; j++)
            {
                if (num1 > num2)
                    num2 += num1;
                else
                {
                    num1 += num2;
                }
            }
            if (num1 > num2)
                num1 += Y;
            else
            {
                num2 += Y;
            }
            cout << "Case " << i << ": ";
            if (num1 == 0 || num2 == 0)
            {
                if (num1 != 0)
                    cout << num1 << endl;
                else
                    cout << num2 << endl;
            }
            else if (num1 > num2)
                cout << GDC(num1, num2) << endl;
            else
            {
                cout << GDC(num2, num1) << endl;
            }
        }

    return 0;
}