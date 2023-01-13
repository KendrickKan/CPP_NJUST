#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x % 2 == 0)
    {
        if (x >= 0)
        {
            cout << "x是一个大于等于0的偶数";
        }
        else
        {
            cout << "x是一个小于0的偶数";
        }
    }
    else
    {
        if (x >= 0)
        {
            cout << "x是一个大于等于0的奇数";
        }
        else
        {
            cout << "x是一个小于0的奇数";
        }
    }
    return 0;
}