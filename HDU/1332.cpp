#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int s;
    string str;
    cin >> s >> str;
    while (1)
    {
        for (int i = 0; i < str.length(); i++)
        {
            cout << ' ';
            if (str[i] == '1' || str[i] == '4')
                for (int j = 0; j < s; j++)
                    cout << ' ';
            else
                for (int j = 0; j < s; j++)
                    cout << '-';
            cout << ' ';
            if (i < str.length() - 1)
                cout << ' ';
        }
        cout << endl;
        for (int x = 0; x < s; x++)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '7')
                {
                    cout << ' ';
                    for (int j = 0; j < s; j++)
                        cout << ' ';
                    cout << '|';
                }
                else if (str[i] == '4' || str[i] == '9' || str[i] == '8' || str[i] == '0')
                {
                    cout << '|';
                    for (int j = 0; j < s; j++)
                        cout << ' ';
                    cout << '|';
                }
                else
                {
                    cout << '|';
                    for (int j = 0; j < s; j++)
                        cout << ' ';
                    cout << ' ';
                }
                if (i < str.length() - 1)
                    cout << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < str.length(); i++)
        {
            cout << ' ';
            if (str[i] == '1' || str[i] == '7' || str[i] == '0')
                for (int j = 0; j < s; j++)
                    cout << ' ';
            else
                for (int j = 0; j < s; j++)
                    cout << '-';
            cout << ' ';
            if (i < str.length() - 1)
                cout << ' ';
        }
        cout << endl;
        for (int x = 0; x < s; x++)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '1' || str[i] == '3' || str[i] == '5' || str[i] == '7' || str[i] == '9' || str[i] == '4')
                {
                    cout << ' ';
                    for (int j = 0; j < s; j++)
                        cout << ' ';
                    cout << '|';
                }
                else if (str[i] == '6' || str[i] == '8' || str[i] == '0')
                {
                    cout << '|';
                    for (int j = 0; j < s; j++)
                        cout << ' ';
                    cout << '|';
                }
                else
                {
                    cout << '|';
                    for (int j = 0; j < s; j++)
                        cout << ' ';
                    cout << ' ';
                }
                if (i < str.length() - 1)
                    cout << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < str.length(); i++)
        {
            cout << ' ';
            if (str[i] == '1' || str[i] == '7' || str[i] == '4')
                for (int j = 0; j < s; j++)
                    cout << ' ';
            else
                for (int j = 0; j < s; j++)
                    cout << '-';
            cout << ' ';
            if (i < str.length() - 1)
                cout << ' ';
        }
        cout << endl;
        cout << endl;
        cin >> s >> str;
        if (s == 0 && str == "0")
            break;
    }
    return 0;
}