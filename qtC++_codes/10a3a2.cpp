#include <iostream>
using namespace std;
class Point
{
	static int defx, defy; //缺省坐标
	static int pcount;	   //对象计数
private:
	int x, y;

public:
	Point()
	{ //缺省构造函数
		x = defx;
		y = defy; //用静态数据成员来初始化
		pcount++; //对象计数加1
	}
	Point(int a, int b)
	{
		x = a;
		y = b;
		pcount++; //对象计数加1
	}
	Point(Point &p)
	{ //拷贝构造函数
		x = p.x;
		y = p.y;
		pcount++;
	}
	~Point()
	{
		pcount--;
	} //析构函数
	static void setDef(int x, int y)
	{ //静态成员函数改变缺省坐标
		defx = x;
		defy = y;
	}
	static int getCount()
	{
		return pcount;
	} //静态成员函数
	void show()
	{
		cout << "x= " << x << " y= " << y;
	}
};
int Point::defx; //缺省初始化为0
int Point::defy = 2;
int Point::pcount = 0;
int main()
{

	Point p1;
	p1.show();
	cout << endl;

	Point::setDef(11, 22);
	Point *p2 = new Point();
	cout << Point::getCount() << " points existing." << endl;
	p2->show();

	cout << endl;
	delete p2;
	cout << Point::getCount() << " points existing." << endl;

	Point p3(33, 44);
	cout << Point::getCount() << " points existing." << endl;
	p3.show();
}
