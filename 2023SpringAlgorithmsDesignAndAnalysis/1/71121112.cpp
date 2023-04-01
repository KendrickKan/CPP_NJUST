#include <bits/stdc++.h>
using namespace std;
int func(int n, int x)
{
    int temp = n;
    int high, low, cur, k;
    high = low = cur = k = 0;
    int ans = 0;
    while (temp != 0)
    {
        cur = temp % 10;
        temp /= 10;
        high = temp;
        if (x == 0)
        {
            high--;
        }
        if (cur > x)
        {
            high++;
        }
        low = pow(10, k);
        ans = ans + high * low;
        if (cur == x)
        {
            ans = ans + n % low + 1;
        }
        k++;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++)
    {
        cout << func(n, i) << endl;
    }
}