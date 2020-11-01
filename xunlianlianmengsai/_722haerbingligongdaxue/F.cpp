#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    string str;
    int wenhao;
    int x, y;
    while (t--)
    {
        wenhao = 0;
        x = 0, y = 0;
        cin >> str;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'R')
                x++;
            else if (str[i] == 'L')
            {
                x--;
            }
            else if (str[i] == 'U')
            {
                y++;
            }
            else if (str[i] == 'D')
            {
                y--;
            }
            else
            {
                wenhao++;
            }
        }
        cout << x - wenhao << ' ' << y - wenhao << ' ' << x + wenhao << ' ' << y + wenhao << endl;
    }

    return 0;
}