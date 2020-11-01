#include <iostream>
#include <string>
using namespace std;
void judge(string str)
{
    int num = 0;
    int x = -1;
    for (int i = 0; i < str.length() - 6; i++)
    {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'a' && str[i + 3] == 'c' && str[i + 4] == 'a' && str[i + 5] == 'b' && str[i + 6] == 'a')
        {
            num++;
        }
    }
    if (num == 1)
    {
        cout << "Yes" << endl;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != '?')
                cout << str[i];
            else
            {
                cout << 'd';
            }
        }
        cout << endl;
    }
    else if (num > 1)
    {
        cout << "No" << endl;
    }
    else
    {
        for (int i = 0; i < str.length() - 6; i++)
        {
            if ((str[i] == 'a' || str[i] == '?') && (str[i + 1] == 'b' || str[i + 1] == '?') && (str[i + 2] == 'a' || str[i + 2] == '?') && (str[i + 3] == 'c' || str[i + 3] == '?') && (str[i + 4] == 'a' || str[i + 4] == '?') && (str[i + 5] == 'b' || str[i + 5] == '?') && (str[i + 6] == 'a' || str[i + 6] == '?'))
            {
                x = i;
                int num1 = 0;
                char temp1 = str[i], temp2 = str[i + 1], temp3 = str[i + 2], temp4 = str[i + 3], temp5 = str[i + 4], temp6 = str[i + 5], temp7 = str[i + 6];
                str[i] = 'a';
                str[i + 1] = 'b';
                str[i + 2] = 'a';
                str[i + 3] = 'c';
                str[i + 4] = 'a';
                str[i + 5] = 'b';
                str[i + 6] = 'a';
                for (int j = i; j < str.length() - 6; j++)
                {
                    if (str[j] == 'a' && str[j + 1] == 'b' && str[j + 2] == 'a' && str[j + 3] == 'c' && str[j + 4] == 'a' && str[j + 5] == 'b' && str[j + 6] == 'a')
                    {
                        num1++;
                    }
                }
                if (num1 == 1)
                {
                    cout << "Yes" << endl;
                    for (int m = 0; m < str.length(); m++)
                    {
                        if (str[m] != '?')
                            cout << str[m];
                        else
                        {
                            if (m == x)
                                cout << 'a';
                            else if (m == x + 1)
                            {
                                cout << 'b';
                            }
                            else if (m == x + 2)
                            {
                                cout << 'a';
                            }
                            else if (m == x + 3)
                            {
                                cout << 'c';
                            }
                            else if (m == x + 4)
                            {
                                cout << 'a';
                            }
                            else if (m == x + 5)
                            {
                                cout << 'b';
                            }
                            else if (m == x + 6)
                            {
                                cout << 'a';
                            }
                            else
                            {
                                cout << 'd';
                            }
                        }
                    }
                    cout << endl;
                }
                else
                {
                    str[i] = temp1;
                    str[i + 1] = temp2;
                    str[i + 2] = temp3;
                    str[i + 3] = temp4;
                    str[i + 4] = temp5;
                    str[i + 5] = temp6;
                    str[i + 6] = temp7;
                    x = -1;
                    continue;
                }
            }
        }
        if (x == -1)
            cout << "No" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        string str;
        cin >> str;
        judge(str);
    }

    return 0;
}