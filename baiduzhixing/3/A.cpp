#include <bits/stdc++.h>
using namespace std;
struct taocan
{
    double x, y;
};
taocan a[105];
double b[105];

double _f(double t, int n)
{
    double m = pow(10, n);
    double result = floor(t * m + 0.5) / m;
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(a, 0, sizeof(0));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].x >> a[i].y;
            double num = (1.0 - a[i].y) / (a[i].x - a[i].y + 1.0);
            num = _f(num, 5);
            b[i] = num;
        }
        double max = b[0];
        for (int j = 1; j < n; j++)
        {
            if (max < b[j])
                max = b[j];
        }
        cout << fixed << setprecision(5) << max << endl;
    }

    return 0;
}