#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    string temp;
    string str1;
    getline(cin, temp);
    getline(cin, str1);
    //cout << str << str1;
    int num = 0;
    for (int i = 0; i <= str1.length() - str.length(); i++)
    {
        bool flag = false;
        for (int j = 0; j < str.length(); j++)
        {
            if (str1[i + j] != str[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            num++;
        }
        if (num == n)
        {
            for (int j = 0; j < str.length(); j++)
            {

                if (str1[i + j] == 'a')
                {
                    str1[i + j] ='z';
                }
                if (str1[i + j] == 'A')
                {
                    str1[i + j] ='Z';
                }
                else
                    str1[i + j]--;
            }
            break;
        }
    }
    if (num < n)
        cout << 'f';
    else
        cout << str1;
    return 0;
}