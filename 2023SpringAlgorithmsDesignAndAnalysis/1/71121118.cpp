#include <bits/stdc++.h>
using namespace std;
int numCount[10];
int main()
{
    int n;
    cin >> n;
    // d为n的位数
    int d = 0;
    int tmp = n;
    while (tmp)
    {
        d++;
        tmp /= 10;
    }
    int topNummult = 0;
    for (int i = d; i >= 1; i--)
    {
        // topNum为n的最高位
        int topNum = n / pow(10, i - 1);
        if (topNum == 0)
        {
            for (int i = 1; i <= topNum; i++)
            {
                numCount[i] += 1;
                topNummult = topNum;
                continue;
            }
        }
        for (int i = 0; i <= topNum; i++)
        {
            numCount[i] += 1;
        }
        for (int i = 0; i < 10; i++)
        {
            numCount[i] += topNummult;
        }
        topNummult = topNummult * topNum;
    }
    numCount[0] -= 1;
    for (int i = 0; i < 10; i++)
    {
        cout << numCount[i] << " ";
    }
    return 0;
}