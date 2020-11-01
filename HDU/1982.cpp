#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string str;
    while (n--)
    {
        cin >> str;
        int num = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '#')
            {
                if (num != 0)
                {
                    cout << (char)('A' + num - 1);
                    num = 0;
                }
                cout << ' ';
            }
            else if (str[i] == '-')
            {
                if (num != 0)
                {
                    cout << (char)('A' + num - 1);
                    num = 0;
                }
            }
            else
            {
                num = (str[i] - '0') + num * 10;
            }
        }
        if (num != 0)
            cout << char('A' + num - 1);
        cout << endl;
    }

    return 0;
}