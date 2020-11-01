#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);

    double a;
    double b;
    scanf("%lf",&a);
    b=(2*sqrt(2)+2*sqrt(3)+2)*a/sqrt(2);
    b=b*b;
    printf("%.5f",b);
    return 0;
}
