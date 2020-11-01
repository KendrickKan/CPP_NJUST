/*
 * @Author: KendrickKan 
 * @Date: 2020-09-27 09:01:06 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-09-27 09:04:26
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return f(n - 1) + f(n - 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int x = f(n);
    int y = 0;
    while (x != 0)
    {
        y += x % 10;
        x /= 10;
    }
    cout << y;
    return 0;
}