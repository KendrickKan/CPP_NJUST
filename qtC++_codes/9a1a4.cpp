#include <iostream>
using namespace std;

class Box
{
private:
    double length;  // 长度
    double breadth; // 宽度
    double height;  // 高度
    bool empty;     // 是否为空
public:
    // 成员函数声明
    double getVolume(void);
    void setLength(double len);
    void setBreadth(double bre);
    void setHeight(double hei);
    void setEmpty(bool a);

    double getLength();
    bool isEmpty();
};

// 成员函数定义
bool Box::isEmpty()
{
    return empty;
}
double Box::getVolume(void)
{
    return length * breadth * height;
}

void Box::setLength(double len)
{
    length = len;
}

void Box::setBreadth(double bre)
{
    breadth = bre;
}

void Box::setHeight(double hei)
{
    height = hei;
}

void Box::setEmpty(bool a)
{
    empty = a;
}

double Box::getLength()
{
    return length;
}

int main()
{
    Box box1;            // 声明 Box1，类型为 Box
    double volume = 0.0; // 用于存储体积

    // box 1 详述
    box1.setLength(6.0);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);
    box1.setEmpty(true);

    // cout << box1.getLength() << endl;

    // box 1 的体积
    volume = box1.getVolume();
    cout << "box1 的体积：" << volume << endl;
    return 0;
}
