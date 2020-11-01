#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    cin >> a;
    int len = a.length();
    ll maxans = 0;
    ll temp = 0;
    for (int i = 0; i < len; i++)
    {
        ll x, y;
        ll xmax, ymax;
        x = y = xmax = ymax = 0;
        if (a[i] == '*' || a[i] == '+')
        {
            for (int j = 0; j < i; j++)
            {
                if (a[j] >= '0' && a[j] <= '9')
                    x = x * 10 + a[j] - '0';
                else
                {
                    if (x > xmax)
                        xmax = x;
                    x = 0;
                }
            }
            for (int j = i + 1; j < len; j++)
            {
                if (a[j] >= '0' && a[j] <= '9')
                    y = y * 10 + a[j] - '0';
                else
                {
                    if (y > ymax)
                        ymax = y;
                    y = 0;
                }
            }
            if (a[i] == '*')
                temp = xmax * ymax;
            else if (a[i] == '+')
                temp = xmax + ymax;
            if (temp > maxans)
                maxans = temp;
        }
    }
    cout << maxans;
    return 0;
}