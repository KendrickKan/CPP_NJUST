#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;
void street(int n, LL id, LL &x, LL &y)
{
    if (n == 1)
    {
        if (id == 1)
            x = 1, y = 1;
        if (id == 2)
            x = 1, y = 2;
        if (id == 3)
            x = 2, y = 2;
        if (id == 4)
            x = 2, y = 1;
    }
    else
    {
        LL _id = (1 << (n - 1)) * (1 << (n - 1));
        if (id <= _id)
            street(n - 1, id, y, x);
        else if (id <= 2 * _id)
        {
            street(n - 1, id - _id, x, y);
            y += 1 << (n - 1);
        }
        else if (id <= 3 * _id)
        {
            street(n - 1, id - 2 * _id, x, y);
            x += 1 << (n - 1);
            y += 1 << (n - 1);
        }
        else
        {
            street(n - 1, id - 3 * _id, y, x);
            x = (1 << n) + 1 - x;
            y = (1 << n - 1) + 1 - y;
        }
    }
}
int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        int n;
        LL h, o;
        cin >> n >> h >> o;
        LL sx, sy, ex, ey;
        street(n, h, sx, sy);
        street(n, o, ex, ey);
        printf("%.0f\n",sqrt((sx - ex) * (sx - ex) + (sy - ey) * (sy - ey)) * 10);
    }

    return 0;
}