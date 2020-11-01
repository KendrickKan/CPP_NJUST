#include <iostream>
using namespace std;
class Box
{
private:
    int ss;

public:             //公有
    double length;  // 长度
    double breadth; // 宽度
    double height;  // 高度
};

int main()
{
    double volume;
    Box Box1;
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    //Box1.ss=6;

    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Box1 的体积：" << volume << endl;
    return 0;
}
