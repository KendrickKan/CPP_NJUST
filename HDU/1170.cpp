#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    //ios::sync_with_stdio(false);
    int t;
    cin >> t;
    char ch;
    int a, b;
    while (t--)
    {
        cin >> ch >> a >> b;
        if (ch == '+')
            cout << a + b << endl;
        else if (ch == '-')
            cout << a - b << endl;
        else if (ch == '*')
            cout << a * b << endl;
        else
        {
            if (a % b == 0)
                cout << a / b << endl;
            else
            {
                printf("%.2f\n", (float)a / b);
            }
        }
    }

    return 0;
}