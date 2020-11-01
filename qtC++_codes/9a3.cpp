#include <iostream>
using namespace std;
class Box
{
public:
   Box(double l, double b, double h)
   {
      length = l;
      breadth = b;
      height = h;
   }
   double Volume()
   {
      return length * breadth * height;
   }
   int compare(Box box)
   {
      //区分 box 与 自己
      return this->Volume() > box.Volume();
   }

private:
   double length;  // Length of a box
   double breadth; // Breadth of a box
   double height;  // Height of a box
};

int main()
{
   Box Box1(3.3, 1.2, 1.5); // Declare box1
   Box Box2(8.5, 6.0, 2.0); // Declare box2

   if (Box1.compare(Box2))
   {
      cout << "Box2 is smaller than Box1" << endl;
   }
   else
   {
      cout << "Box2 is equal to or larger than Box1" << endl;
   }
   return 0;
}
