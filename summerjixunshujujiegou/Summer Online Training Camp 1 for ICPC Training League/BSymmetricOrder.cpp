#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string str[20];
    int x = 1;
    while (n != 0)
    {
        for (int i = 1; i <= n; i++)
            cin >> str[i];
        cout << "SET " << x << endl;
        x++;
        for (int i = 1; i <= n; i += 2)
            cout << str[i] << endl;
        for (int i = n - (n % 2); i > 1; i -= 2)
            cout << str[i] << endl;
        cin >> n;
    }

    return 0;
}