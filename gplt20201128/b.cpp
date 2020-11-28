#include <bits/stdc++.h>
using namespace std;
int main()
{
    double t;
    cin >> t;
    int a;
    cin >> a;
    double x;
    if (a == 0)
        x = 2.455;
    else
        x = 1.26;
    double y;
    cin >> y;
    double z;
    z = t * x;
    printf("%.2f ", z);
    if (z >= y)
        cout << "T_T";
    else
        cout << "^_^";
    return 0;
}