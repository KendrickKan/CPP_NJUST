#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ifseven(int x)
{
    if (x % 7 == 0)
        return 1;

    else
    {
        string a = "";
        while (x != 0)
        {
            int m = x % 10;
            x /= 10;
            a += ('0' + m);
        }
        for (int i = 0; i < a.length(); i++)
            if (a[i] == '7')
            {
                return 1;
                break;
            }
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[4];
    memset(a, 0, sizeof(a));
    int ans = 0;
    for (int i = 1; ans < n; i++)
    {
        if (ifseven(i))
        {
            a[i % 4]++;
        }
        else
            ans++;
    }
    cout << a[1] << endl
         << a[2] << endl
         << a[3] << endl
         << a[0];
    return 0;
}