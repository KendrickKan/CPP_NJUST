#include <bits/stdc++.h>
using namespace std;
int a[10];
void f(int n)
{
    int k = log10(n) + 1;
    int h = (int)(n / (int)pow(10, k - 1));
    if (n > 0 && n < 10)
    {
        for (int i = 0; i <= n; i++)
        {
            a[i] += 1;
        }
        for (int i = n + 1; i < 10; i++)
        {
            a[i] += 0;
        }
        return;
    }
    else
    {
        f(h * (int)pow(10, k - 1) - 1);
        f(n - h * (int)pow(10, k - 1));
        a[h] += (n - h * (int)pow(10, k - 1)) + 1;
    }
}
int main()
{
    int n;
    cin >> n;
    f(n);
    a[0]--;
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}