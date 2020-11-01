#include <iostream>
using namespace std;
class base
{
protected:
	int x;
	int y;

public:
	base()
	{
		cout << "缺省base()" << endl;
	}
	base(int x, int y)
	{
		cout << "含参base()" << endl;
		this->x = x;
		this->y = y;
	}
	~base()
	{
		cout << "~base()" << endl;
	}
};
class onbase : base
{
private:
	int z;

public:
	onbase()
	{
		cout << "缺省onbase()" << endl;
	}
	onbase(int x, int y, int z) : base(x, y)
	{
		cout << "含参onbase()" << endl;
		this->z = z;
	}
	~onbase()
	{
		cout << "~onbase()" << endl;
	}
};

int main()
{
	onbase on1;
	cout << endl;
	onbase on2(1, 2, 3);
}
