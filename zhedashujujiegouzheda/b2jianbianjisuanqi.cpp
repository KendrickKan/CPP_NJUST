#include <iostream>
using namespace std;
int main()
{
    char ch = '0';
    int sum, x, iserror=0;
    cin >> sum;
    while (ch != '=')
    {
        cin >> ch;
        if (ch == '=')
            break;
        cin >> x;
        if (ch == '+')
            sum += x;
        else if (ch == '-')
            sum -= x;
        else if (ch == '*')
            sum *= x;
        else if (ch == '/')
        {
            if (x != 0)
                sum /= x;
            else
            {
                iserror = 1;
                break;
            }
        }
        else
        {
            iserror = 1;
            break;
        }
    }
    if (iserror == 1)
        cout << "ERROR";
    else
    {
        cout << sum;
    }

    return 0;
}