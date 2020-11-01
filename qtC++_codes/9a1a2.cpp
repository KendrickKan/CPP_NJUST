#include <iostream>
using namespace std;

class Date
{
private:
  int year, month, day;

public:
  void setDate(int y, int m, int d);
  bool isLeapYear();
  void print()
  {
    cout << year << "." << month << "." << day << endl;
  }
};

//类的实现
void Date::setDate(int y, int m, int d)
{
  year = y;
  month = m;
  day = d;
}

bool Date::isLeapYear()
{
  return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int main()
{
  Date date;
  date.setDate(2019, 7, 29);
  date.print();
  return 0;
}
