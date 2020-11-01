#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrimeNumber(int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if ((n % i) == 0)

            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        int t = n / 2;
        while (t > 1)
        {
            if (isPrimeNumber(t) && isPrimeNumber(n - t))
            {
                cout << t << ' ' << n - t << endl;
                break;
            }
            t--;
        }
    }
    return 0;
}