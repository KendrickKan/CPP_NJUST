#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
    ios::sync_with_stdio(false);
    ll t, n, sum, s1, s2, num = 1, h, l, i, q;
    cin >> t;
    while (t--)
    {
        cin >> h >> l;
        sum = 1;
        s2 = 0;
        if (l == 1)
            cout << "Case " << num++ << ": " << h + 1 << endl;
        else
        {
            for (i = 2; i <= l; i = i * 2)
            {
                if (i == 2)
                    s1 = (h - s2) * (i - i / 2 + 1);
                else
                    s1 = (h - s2) * (i - i / 2);
                sum += s1;
                s2++;
            }
            if (l == i / 2)
            {
                q = 0;
            }
            else
                q = l - i / 2;
            sum = sum + q * (h - s2);
            cout << "Case " << num++ << ": " << sum << endl;
        }
    }
}