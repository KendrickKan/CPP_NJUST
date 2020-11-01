#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        ll a, b, c;
        ll r, l, m;
        cin >> r >> l >> m;
        ll cha = l - r;
        ll shang, xia;
        xia = m + (-1 * cha);
        shang = m + cha;
        for (ll y = r; y < l + 1; y++)
        {
            ll flag = (shang - xia) / y;
            if (flag > 0)
            {
                a = y;
                ll x = (xia / y + 1) * y;
                cha = m - x;
                goto next;
            }
        }
    next:
        if (cha > 0)
        {
            c = r;
            b = c + cha;
        }
        else if (cha == 0)
        {
            c = b = r;
        }
        else
        {
            b = r;
            c = b + (-1 * cha);
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}