#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a[6], ans = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
        ans += a[i] * (i - 1);
    }
    sort(a, a + 6);
    printf("%.3f", fabs(ans - 3.5) / a[5]);
    return 0;
}