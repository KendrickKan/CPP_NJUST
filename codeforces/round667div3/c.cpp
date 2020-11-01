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
        int n, x, y;
        cin >> n >> x >> y;
        int cha = abs(x - y);
        if (n == 2)
            cout << x << ' ' << y << endl;
        else
        {
            if (cha <= n - 1)
            {
                if (max(x, y) >= n)
                {
                    for (int i = max(x, y); i >= n - max(x, y); i--)
                        cout << i << ' ';
                    cout << endl;
                }
                else
                {
                    for (int i = 1; i <= n; i++)
                        cout << i;
                    cout << endl;
                }
            }
            else
            {
                for (int i = cha + 1; i > cha - n; i--)
                    ;
            }
        }
    }

    return 0;
}