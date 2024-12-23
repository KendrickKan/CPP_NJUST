#include <iostream>
using namespace std;

// bool 类型只有两个值：true 1 和 false 0
// 0赋值给bool类型的变量，结果是false
// 非0赋值给bool类型的变量，结果是true
int main()
{
    bool b1 = true;
    int i = b1;
    bool b2 = -256;
    cout << "i=" << i << endl;
    cout << "b1=" << b1 << endl;
    cout << "b2=" << b2 << endl;
    cout << true << endl;
    return 0;
}