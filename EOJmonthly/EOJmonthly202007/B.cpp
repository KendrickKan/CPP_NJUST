#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char x;
    int num;
    int sum = 0;
    while (n--)
    {
        cin >> x;
        cin >> num;

        if (x == 'M')
            num = pow(2.0, num)-1;
        if (num > sum)
            sum = num;
    }
    cout << sum;

    return 0;
}