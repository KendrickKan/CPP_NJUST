#include <iostream>

using namespace std;

class Car
{
public:
    void run()
    {
        cout << "run" << endl;
    }
};

class XCar : public Car
{
    int name;
};
int main(int argc, char const *argv[])
{
    XCar x();
    x.run();
    return 0;
}
