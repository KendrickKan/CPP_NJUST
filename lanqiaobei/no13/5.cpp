#include <iostream>
using namespace std;
int maxnum = 998244353;
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        int x, y;
        cin >> x >> y;
        int fenzi = y;
        int fenmu = y - x;
        if (y % x == 0)
            cout << y / x;
    }
    return 0;
}