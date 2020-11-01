#include <time.h>
#include <iostream>
using namespace std;
class Date
{
private:
	int year, month, day;

public:
	Date(int y, int m, int d)
	{ //构造函数1 含有参数的构造函数
		cout << "构造函数1" << endl;
		year = y;
		month = m;
		day = d;
	}
	Date()
	{ //构造函数2：当前日期  不含参数的构造函数
		cout << "构造函数2" << endl;
		time_t ltime = time(NULL);	   //取得当前时间
		tm *today = localtime(&ltime); //转换为本地时间
		year = today->tm_year + 1900;  //取得当前年份
		month = today->tm_mon + 1;	   //取得当前月份,0-11
		day = today->tm_mday;		   //取得当前日,1-31
	}
	void print()
	{
		cout << year << "." << month << "." << day << endl;
	}
};
int main()
{
	Date date(2020, 7, 29);
	date.print();

	cout << endl;

	Date date_test;
	date_test.print();

	Date dates[4] = {Date(2000, 10, 7),
					 Date(2012, 11, 2),
					 Date(2013, 12, 8)}; //创建4个Date对象
	cout << endl;
	dates[3].print();
	dates[3] = Date(2014, 12, 13); //对第4个元素重置新对象

	for (int i = 0; i < 4; i++)
	{
		dates[i].print();
	}
	system("pause");
}
