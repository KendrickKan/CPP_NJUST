#include <bits/stdc++.h>
using namespace std;
int f(int k, int n)
{
    int i = 1;
    int count = 0;
    int current = 0;
    int high = 0;
    int low = 0;
    while (n / i != 0)
    {
        current = (n / i) % 10;
        high = n / (i * 10);
        low = n - (n / i) * i;
        if (current < k)
        {
            count += high * i;
        }
        else if (current == k)
        {
            count += high * i + low + 1;
        }
        else
        {
            count += (high + 1) * i;
        }
        i *= 10;
    }
    if (k == 0)
    {
        if (n < 10)
        {
            count--;
        }
        else
        {
            count -= i / 10;
            count--;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        cout << f(i, n) << endl;
    }
    return 0;
}