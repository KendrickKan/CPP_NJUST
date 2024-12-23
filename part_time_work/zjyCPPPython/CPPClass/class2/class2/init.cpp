#include <iostream>
using namespace std;
int main()
{
    // 一个是0 一个是8 是由于编译器自己的优化
    // int num1 = 1; //good: initialized variable
    int num1; //bad: uninitialized variable
    int num2; //bad: uninitialized variable
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}
