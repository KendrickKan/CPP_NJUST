#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        if (n != 1)
        {
            string str;
            cin >> str;
            long long num = 1;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == 'y')
                {
                    num *= 2;
                }
                else
                    num = 2 * num + 1;
            }
            cout << num - pow(2, n) + 1 << endl;
        }
        else
        {
            string str;
            cin >> str;
            if (str == "y")
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}