#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int srt;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'b' || str[i] == 'c')
        {
            cout << 2;
        }
        if (str[i] == 'd' || str[i] == 'e' || str[i] == 'f')
        {
            cout << 3;
        }
        if (str[i] == 'g' || str[i] == 'h' || str[i] == 'i')
        {
            cout << 4;
        }
        if (str[i] == 'j' || str[i] == 'k' || str[i] == 'l')
        {
            cout << 5;
        }
        if (str[i] == 'm' || str[i] == 'n' || str[i] == 'o')
        {
            cout << 6;
        }
        if (str[i] == 'p' || str[i] == 'q' || str[i] == 'r' || str[i] == 's')
        {
            cout << 7;
        }
        if (str[i] == 't' || str[i] == 'u' || str[i] == 'v')
        {
            cout << 8;
        }
        if (str[i] == 'w' || str[i] == 'x' || str[i] == 'y' || str[i] == 'z')
        {
            cout << 9;
        }
    }
    return 0;
}