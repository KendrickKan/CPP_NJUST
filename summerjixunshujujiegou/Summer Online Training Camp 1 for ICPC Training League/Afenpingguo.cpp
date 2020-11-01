#include <iostream>
using namespace std;
int fangapple(int m, int n)
{
    if (n == 1 || m == 0)
        return 1;
    if (m < n)
        return fangapple(m, m);
    else
        return fangapple(m, n - 1) + fangapple(m - n, n);
}
int main() 
{
    int t, m, n;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        cout << fangapple(m, n) << endl;
    }

    return 0;
}