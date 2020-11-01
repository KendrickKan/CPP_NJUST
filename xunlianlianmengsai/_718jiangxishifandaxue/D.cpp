#include <iostream>
#include <string>
using namespace std;
int changestringtonum(string str,int n)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num = num * 10 + str[i] - '0';
    }
    return num;
}
bool ishavefactors(int num1, int num2)
{
    int min = num1 < num2 ? num1 : num2;
    for (int i = 2; i <= min; i++)
        if (num1 % i == 0 && num2 % i == 0)
            return true;
    return false;
}
void solve(string str)
{
    int num1, num2;
    string str1, str2;
    for (int i = 0; i < str.length()-1; i++)
    {
        str1=str2="        ";
        for (int j = 0; j <= i; j++)
            str1[j] = str[j];
        for (int j = i + 1; j < str.length(); j++)
            str2[j - i - 1] = str[j];
        num1 = changestringtonum(str1,i+1);
        num2 = changestringtonum(str2,str.length()-i-1);
        if (!ishavefactors(num1, num2))
        {
            cout << num1 << ' ' << num2 << endl
                 << endl;
            return;
        }
    }
    cout << "Not relative";
    cout << endl
         << endl;
}
int main()
{
    int n, x = 1;
    cin >> n;
    string str;
    while (n--)
    {
        cin >> str;
        cout << "Ticket #" << x << ":" << endl;
        solve(str);
        //  cout << changestringtonum(str) << endl;
        x++;
    }

    return 0;
}