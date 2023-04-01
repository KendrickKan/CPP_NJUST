#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int c[10] = {0};
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp)
        {
            c[tmp % 10]++;
            tmp /= 10;
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        cout << c[i] << endl;
    }
}