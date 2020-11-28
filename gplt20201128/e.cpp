#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int minyu;
    cin >> minyu;
    int wuchayuzhi;
    cin >> wuchayuzhi;
    int maxnum = max(max(max(a, b), c), d);
    int di[4];
    memset(di, 0, sizeof(di));
    int num = 0;
    if (a < minyu || abs(a - maxnum) > wuchayuzhi)
    {
        di[0] = 1;
        num++;
    }
    if (b < minyu || abs(b - maxnum) > wuchayuzhi)
    {
        di[1] = 1;
        num++;
    }
    if (c < minyu || abs(c - maxnum) > wuchayuzhi)
    {
        di[2] = 1;
        num++;
    }
    if (d < minyu || abs(d - maxnum) > wuchayuzhi)
    {
        di[3] = 1;
        num++;
    }
    if (num == 0)
        cout << "Normal";
    else if (num == 1)
    {
        cout << "Warning: please check #";
        if (di[0] == 1)
            cout << 1 << "!";
        if (di[1] == 1)
            cout << 2 << "!";
        if (di[2] == 1)
            cout << 3 << "!";
        if (di[3] == 1)
            cout << 4 << "!";
    }
    else
        cout << "Warning: please check all the tires!";
    return 0;
}