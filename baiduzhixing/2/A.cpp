#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        double n, m, p;
        cin >> n >> m >> p;
        int num = 0;
        double x = m * (1.00 - p * 0.01);
        int y = (int)x;
        if (n < m)
            cout << 0 << endl;
        else
        {
            int test = ((int)n - (int)m) % ((int)m - (int)y);
            num = (n - m) / (m - y);
            int shnegyu = m + test;
            while (shnegyu >= m)
            {
                num++;
                shnegyu = shnegyu - m + y;
            }

            cout << num << endl;
        }
    }

    return 0;
}
