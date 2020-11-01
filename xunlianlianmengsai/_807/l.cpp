#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000000.0
int main()
{
    double k, p, x;
    scanf("%lf%lf%lf", &k, &p, &x);
    double ans = MAXN;
    for (double m = 1; m <= 100000; m++)
    {
        double tmp = 0.0;
        tmp = m * x + k / (m * 1.0) * p;
        ans = min(ans, tmp);
    }
    printf("%.3f\n", ans);
    return 0;
}
