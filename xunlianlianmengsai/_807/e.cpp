#include <bits/stdc++.h>
using namespace std;
long long n;
double vx, vy, sum, v, l, r, x;
int main()
{
    while (cin >> n >> x >> vx)
    {
        sum = 0;
        while (n--)
        {
            cin >> l >> r >> vy;
            sum += (r - l) * vy;
        }
        sum = sum / x;
        if (fabs(sum) > vx)
        {
            cout << "Too hard" << endl;
            return 0;
        }
        v = sqrt(vx * vx - sum * sum);
        if (v < vx / 2)
            cout << "Too hard" << endl;
        else
        {
            v = x / v;
            printf("%.3f", v);
        }
    }
    return 0;
}