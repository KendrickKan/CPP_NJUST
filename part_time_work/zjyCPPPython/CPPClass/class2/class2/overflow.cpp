#include <iostream>
using namespace std;

int main()
{
    // overflow 溢出
    long long a = 56789;
    long long b = 56789;
    long long c = a * b;
    cout << "c = " << c << endl;

    // unsigned int c1 = a * b; //danger operation
    // cout << "c1 = " << c1 << endl;
    return 0;
}
