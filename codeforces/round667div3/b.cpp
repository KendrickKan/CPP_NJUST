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
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll an, bn;
        an = a - x;
        bn = b - y;
        if (n >= (an + bn))
            cout << x * y << endl;
        else
        {
            if (n >= an && n >= bn)
            {
                if (x == y)
                {
                    if ((b - (n - an)) == (a - (n - bn)))
                        cout << x * (b - (n - an)) << endl;
                    else
                    {
                        if ((b - (n - an)) < (a - (n - bn)))
                            cout << x * (b - (n - an)) << endl;
                        else
                            cout << y * (a - (n - bn)) << endl;
                    }
                }
                else
                {
                    if (x < y)
                        cout << x * (b - (n - an)) << endl;
                    else
                        cout << y * (a - (n - bn)) << endl;
                }
            }
            else
            {
                ll min = 1e18;
                for (int i = 0; i <= n; i++)
                {
                    if ((a - i) >= x && (b - (n - i)) >= y)
                    {
                        ll cheng = (a - i) * (b - (n - i));
                        if (cheng < min)
                            min = cheng;
                    }
                }
                cout << min << endl;
            }
        }
    }

    return 0;
}