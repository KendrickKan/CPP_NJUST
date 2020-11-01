#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) && n != 0)
    {
        for (int i = (int)sqrt(2 * n); i >= 1; i--)
        {
            double temp = (double)i;
            if ((2 * n) / temp - (2 * n) / i == 0)
            {
                int flag = (2 * n - i * i) / i;
                double abc = (double)i;
                if ((2 * n - abc * abc) / abc - flag != 0)
                    continue;
                int ans = (flag + 1) / 2;
                if ((flag + 1) / 2.0 - ans != 0)
                    continue;
                cout << ans << " " << i << endl;
                break;
            }
        }
    }
    return 0;
}