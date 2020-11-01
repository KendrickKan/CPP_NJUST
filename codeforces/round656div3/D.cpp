#include <iostream>
#include <string>
using namespace std;
int findmin(string str, int n, int flag)
{
    if (n == 1)
    {
        if (str[0] == 'a' + flag)
            return 0;
        else
            return 1;
    }
    int x = n >> 1;
    int numqian = 0, numhou = 0, minnum = 0;
    for (int i = 0; i < x; i++)
        if (str[i] != 'a' + flag)
            numqian++;
    for (int i = x; i < n; i++)
        if (str[i] != 'a' + flag)
            numhou++;
    if (numqian != numhou)
    {
        if (numqian < numhou)
            minnum = numqian;
        else if (numqian > numhou)
            minnum = numhou;
        string newstr;
        if (minnum == numqian)
            for (int i = 0; i < x; i++)
                newstr[i] = str[i];
        else
            for (int i = 0; i < x; i++)
                newstr[i] = str[i + x];

        return minnum + findmin(newstr, x, flag + 1);
    }
    else
    {
        string newstr1, newstr2;
        for (int i = 0; i < x; i++)
            newstr1[i] = str[i];
        for (int i = 0; i < x; i++)
            newstr2[i] = str[i + x];
        if (findmin(newstr1, x, flag + 1) < findmin(newstr2, x, flag + 1))
            return numhou + findmin(newstr1, x, flag + 1);
        else
            return numqian + findmin(newstr2, x, flag + 1);
    }
}
int main()
{
    int t;
    string str;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> str;
        int flag = 0;
        cout << findmin(str, n, flag) << endl;
    }
    return 0;
}