#include <iostream>
using namespace std;
class Date{
private:
  int year, month, day;
public:
  void setDate(int year, int month, int day);
  bool isLeapYear();
  void print(){
     cout<<year<<"."<<month<<"."<<day<<endl;
  }
};
 //学习 this 的使用 
void Date::setDate(int year, int month, int day){
  this->year = year;	
  this->month = month; 
  this->day = day;
}
/*
void Date::setDate(int y, int m, int d){
  year = y;	
  month = m; 
  day = d;
}
*/
bool Date::isLeapYear(){
  return year%400 == 0 || year%4 == 0 && year%100 != 0;
}
int main(){
	Date date;
	date.setDate(2019,7,29);
	date.print();
	return 0;
}
