#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    a = a * 1.0 / 100;
    b = b * 1.0 / 100;
    c = c * 1.0 / 100;
    d = d * 1.0 / 100;
    double num = 0.0;
    double kal = 0.0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        int tempnum;
        double tempkal;
        cin >> tempnum;
        cin >> tempkal;
        kal += tempkal;
        if (ch == 'M')
        {
            num += a * 1.0 * tempnum;
        }
        else if (ch == 'V')
        {
            num += b * 1.0 * tempnum;
        }
        else if (ch == 'R')
        {
            if (tempnum > 200)
                num += c * 1.0 * (tempnum - 200);
        }
        else if (ch == 'S')
        {
            num += d * 1.0 * tempnum;
        }
        kal = tempkal * 1.0 / 100 * tempnum;
    }
    if (kal < 900.0)
    {
        num *= 0.9;
    }
    printf("%.2f\n", num);
    return 0;
}
6
a1 a2 1000
a1 a3 1600
a3 d4 1200
b0 a11 2200
b1 c21 3600
a11 b3 1500