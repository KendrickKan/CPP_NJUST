#include <bits/stdc++.h>
using namespace std;
void swap(string &num1, string &num2)
{
    string str = num1;
    num1 = num2;
    num2 = str;
}
string add(string num1, string num2)
{
    if (num1.length() < num2.length())
        swap(num1, num2);
    int len1 = num1.length(), len2 = num2.length(), jinwei = 0, number;
    for (int i = 0; i < len2; i++)
    {
        number = num1[len1 - i - 1] - '0' + num2[len2 - i - 1] - '0' + jinwei;
        jinwei = number / 10;
        number %= 10;
        num1[len1 - i - 1] = number + '0';
    }
    for (int j = len2; j < len1; j++)
    {
        number = num1[len1 - j - 1] - '0' + jinwei;
        jinwei = number / 10;
        number %= 10;
        num1[len1 - j - 1] = number + '0';
    }
    if (jinwei == 1)
    {
        reverse(num1.begin(), num1.end());
        num1 += "1";
        reverse(num1.begin(), num1.end());
    }
    return num1;
}
bool judgebig(string temp, string maxans)
{
    if (temp.length() != maxans.length())
        return temp.length() > maxans.length();
    else
    {
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] != maxans[i])
            {
                return temp[i] > maxans[i];
            }
        }
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    cin >> a;
    int len = a.length();
    string maxans, temp;
    maxans = temp = "0";
    for (int i = 0; i < len; i++)
    {
        string x, y, xmax, ymax;
        x = y = xmax = ymax = "";
        if (a[i] == '+')
        {
            for (int j = 0; j < i; j++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (a[j] >= '0' && a[j] <= '9')
                        x += a[j];
                    else
                    {
                        if (judgebig(x, xmax))
                            xmax = x;
                        x = "";
                    }
                }
            }
            for (int j = i + 1; j < len; j++)
            {
                if (a[j] >= '0' && a[j] <= '9')
                    y += a[j];
                else
                {
                    if (judgebig(y, ymax))
                        ymax = y;
                    y = "";
                }
            }
            if (xmax == "")
                xmax = "0";
            if (ymax == "")
                ymax = "0";
            temp = add(xmax, ymax);
            if (judgebig(temp, maxans))
                maxans = temp;
        }
    }
    cout << maxans;
    return 0;
}