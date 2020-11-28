#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char a;
    cin >> n;
    cin >> a;
    getchar();
    string str;
    getline(cin, str);
    if (str.length() >= n)
    {
        for (int i = str.length() - n; i < str.length(); i++)
            cout << str[i];
    }
    else
    {
        for (int i = 0; i < n - str.length(); i++)
            cout << a;
        cout << str;
    }

    return 0;
}