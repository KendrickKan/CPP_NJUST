#include <iostream>
using namespace std;
class Box
{
public:
   // 构造函数定义
   Box(double l = 2.0, double b = 2.0, double h = 2.0)
   {
      cout << "Constructor called." << endl;
      length = l;
      breadth = b;
      height = h;
   }
   double Volume()
   {
      return length * breadth * height;
   }

private:
   double length;  // Length of a box
   double breadth; // Breadth of a box
   double height;  // Height of a box
};

int main()
{
   Box Box1(3, 4, 5);      // Declare box1
   Box Box2(10, 6.0, 2.0); // Declare box2

   Box *ptrBox; // Declare pointer to a class.
   // 保存第一个对象的地址
   ptrBox = &Box1;
   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box1: " << ptrBox->Volume() << endl;
   // 保存第二个对象的地址
   ptrBox = &Box2;
   // 现在尝试使用成员访问运算符来访问成员
   cout << "Volume of Box2: " << ptrBox->Volume() << endl;

   Box *box1 = new Box(3, 3, 3);
   cout << "Volume of box1: " << box1->Volume() << endl;
   return 0;
}
