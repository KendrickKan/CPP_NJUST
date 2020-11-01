#include <iostream>
using namespace std;
// 基类
class Shape
{
public:
   void setWidth(int w)
   {
      width = w;
   }
   void setHeight(int h)
   {
      height = h;
   }
   int getWidth()
   {
      cout << "jilei" << endl;
      return width;
   }

protected:
   int width;
   int height;
};

// 派生类
class Rectangle : public Shape
{
public:
   int getWidth()
   {
      cout << "paisheng" << endl;
      //return width;
      return this->Shape::getWidth();
      // return this->getWidth();
      //调用其基类的 成员函数时
   }
   int getArea()
   {
      return (width * height);
   }
};

int main(void)
{
   Rectangle Rect;

   Rect.setWidth(5);
   Rect.setHeight(7);

   cout << Rect.getWidth() << endl;
   // 输出对象的面积
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}
