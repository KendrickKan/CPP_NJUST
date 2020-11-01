#include <iostream>
#include <cstring>
using namespace std;
class Base
{
public:
  void print()
  {
    cout << "print() in Base." << endl;
  }
  void print(int a)
  {
    cout << "print(int a) in Base." << endl;
  }
  void print(string s)
  {
    cout << "print(string s) in Base." << endl;
  }
};

class Derived : public Base
{
public:
  void print()
  {
    cout << "print() in Derived." << endl;
  }
};

int main()
{
  Derived d;
  d.print();
  //d.print(10);
  //d.print("");
  return 0;
}
