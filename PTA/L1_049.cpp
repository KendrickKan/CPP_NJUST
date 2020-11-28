#include <bits/stdc++.h>
using namespace std;
int a[101];
int ai[101];
int b[101][101];
int main()
{
    int t;
    cin >> t;
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int maxnum = sum * 10;
    int i = 0;
    int num = 0;
    int temp = 0;
    int qian = 1111111;
    while (temp < maxnum)
    {
        //int temp = i % t;
        // b[i % t][ai[i % t]] = num + 1;
        // ai[i % t]++;
        if (ai[i % t] < a[i % t] * 10)
        {
            if (i % t == qian)
            {
                num++;
                //temp--;
            }
            b[i % t][ai[i % t]] = num + 1;
            ai[i % t]++;
            temp++;
            num++;
            qian = i % t;
        }
        i++;
    }
    for (int x = 1; x <= t; x++)
    {
        cout << "#" << x;
        for (int j = 0; j < a[x - 1] * 10; j++)
        {
            if (j % 10 == 0)
                cout << endl;
            cout << b[x - 1][j];
            if (j == a[x - 1] * 10 - 1)
                cout << endl;
            if (j % 10 != 9)
                cout << " ";
        }
    }
    return 0;
}