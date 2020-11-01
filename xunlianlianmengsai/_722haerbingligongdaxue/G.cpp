#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int T, n, m, k;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        if (k > n)
            cout << "NO" << endl;
        else if (n % m == k || (n % m == 0 && m == k))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
