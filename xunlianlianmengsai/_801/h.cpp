#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    char a[4];
    int h, m, s;
    h = m = s;
    int x = n;
    while (n--)
    {
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        s += (a[2] - '0') * 10 + (a[3] - '0');
        if (n != 1 && x != 1)
            s -= t;

        if (s >= 60)
        {
            m++;
            s -= 60;
        }
        m += a[0] - '0';
        if (m >= 60)
        {
            h++;
            m -= 60;
        }
    }
    if (h == 0)
        cout << "00";
    else if (h < 10 && h > 0)
        cout << '0' << h;
    else
    {
        cout << h;
    }
    cout << ':';
    if (m == 0)
        cout << "00";
    else if (m < 10 && m > 0)
        cout << '0' << m;
    else
    {
        cout << m;
    }
    cout << ':';
    if (s == 0)
        cout << "00";
    else if (s < 10 && s > 0)
        cout << '0' << s;
    else
    {
        cout << s;
    }
    return 0;
}