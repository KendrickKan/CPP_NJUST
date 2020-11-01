#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    ll a[7];
    ll b[7];
    while (t--)
    {
        memset(b, 0, sizeof(b));
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        ll minnum = 1e10;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            if (a[i] < minnum)
                minnum = a[i];
        }
        sort(b + 1, b + n + 1);
        int total = 1;
        if (n == 1)
            cout << "YES" << endl;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                int j = i;
                for (; j <= n; j++)
                    if (a[j] == b[i])
                    {
                        if (j == i)
                            continue;
                        if (__gcd(a[j], a[i]) != minnum)
                        {
                            cout << "NO" << endl;
                            goto stop1;
                        }
                        ll temp;
                        temp = a[j];
                        a[j] = a[i];
                        a[i] = temp;
                        total++;
                    }
                if (total != i)
                    i = total - 1;
            }
            cout << "YES" << endl;
        stop1:;
        }
    }

    return 0;
}