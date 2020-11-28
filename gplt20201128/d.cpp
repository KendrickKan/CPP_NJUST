#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        double t;
        cin >> t;
        t = 1.0 / t;
        sum += t;
    }
    printf("%.2f", n * 1.0 / sum);
    return 0;
}