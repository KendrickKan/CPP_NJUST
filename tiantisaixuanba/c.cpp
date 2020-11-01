/*
 * @Author: KendrickKan 
 * @Date: 2020-09-27 09:24:07 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-09-27 09:40:29
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a[20];
    memset(a, 0, sizeof(a));
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] <= '9' && str[i] > '0')
            a[str[i] - '0']++;
        else if (str[i] == '0')
            a[10]++;
        else if (str[i] == 'J')
            a[11]++;
        else if (str[i] == 'Q')
            a[12]++;
        else if (str[i] == 'K')
            a[13]++;
        else if (str[i] == 'A')
            a[14]++;
        else if (str[i] == 'X')
            a[15]++;
        else if (str[i] == 'Y')
            a[16]++;
    }
    int two = 0, three = 0;
    for (int i = 0; i < 20; i++)
    {
        if (a[i] != 0)
            cnt++;
        if (a[i] >= 2)
        {
            cnt++;
            two++;
            if (a[i] >= 3)
            {
                cnt++;
                three++;
                if (a[i] >= 4)
                    cnt++;
            }
        }
    }
    cnt += (two - 1) * three;
    if (a[15] != 0 && a[16] != 0)
        cnt++;
    for (int i = 3; i < 11; i++)
    {
        if (a[i] != 0 && a[i + 1] != 0 && a[i + 2] != 0 && a[i + 3] != 0 && a[i + 4] != 0)
            cnt++;
    }
    cout << cnt;
    return 0;
}