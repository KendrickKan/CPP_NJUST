#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int num = 0;
    int begin = 0;
    string x;
    int sum = 0;
    while (getline(cin, str))
    {
        // if (num != 0)
        //     getchar();
        if (str == ".")
            break;
        num++;
        for (int i = 0; i < str.length() && (i + 13) < str.length(); i++)
        {
            if (str[i] == 'c' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == '1' && str[i + 4] == ' ' && str[i + 5] == 'h' && str[i + 6] == 'u' && str[i + 7] == 'o' && str[i + 8] == '3' && str[i + 9] == ' ' && str[i + 10] == 'g' && str[i + 11] == 'u' && str[i + 12] == 'o' && str[i + 13] == '1')
            {
                if (begin == 0)
                    begin = num;
                sum++;
                break;
            }
        }
        getchar();
    }
    cout << num -1 << endl;
    if (sum != 0)
    {
        cout << begin << " " << sum;
    }
    else
        cout << "-_-#";
    return 0;
}