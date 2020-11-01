#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    cin >> n;
    LL x, y, z;
    while (n--)
    {
        cin >> x >> y >> z;
        if (x != y && y != z && x != z)
            cout << "NO" << endl;
        else if (x == y && y == z)
        {
            cout << "YES" << endl;
            cout << x << ' ' << x << ' ' << x << endl;
        }
        else
        {
            if (x == y && x > z)
            {
                cout << "YES" << endl;
                cout << x << ' ' << z << " 1" << endl;
            }

            else if (x == z && x > y)
            {
                cout << "YES" << endl;
                cout << x << ' ' << y << " 1" << endl;
            }
            else if (z == y && z > x)
            {
                cout << "YES" << endl;
                cout << z << ' ' << x << " 1" << endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
            
        }
    }

    return 0;
}