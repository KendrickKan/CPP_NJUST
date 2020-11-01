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
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string a;
        cin >> a;
        int midk = 0;
        for (int i = 0; i < k; i++)
        {
            char x = a[i];
            int flag = 0;
            for (int j = i + k; j < n; j += k)
            {
                if (a[j] == '?')
                    continue;
                if (a[i] == '?' && a[j] != '?')
                {
                    x = a[j];
                    a[i] = a[j];
                    continue;
                }
                if (x != '?' && a[i] != a[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                midk = 1;
                break;
            }
        }
        int p = 0, q = 0;
        for (int i = 0; i < k; i++)
        {
            if (a[i] == '0')
                q++;
            if (a[i] == '1')
                p++;
        }
        if (q > k / 2 || p > k / 2)
            midk = 1;
        if (midk == 0)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}