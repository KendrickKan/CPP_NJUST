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
        if (k == 0)
        {
            if (n % 2 == 0)
                cout << 0 << endl;
            else
            {
                cout << 1 << endl;
            }
        }
        else
        {
            if (n < k)
                cout << k - n << endl;
            else
            {
                if ((n % 2 == 0 && k % 2 == 0) || (n % 2 != 0 && k % 2 != 0))
                    cout << 0 << endl;
                else
                {
                    cout << 1 << endl;
                }
            }
        }
    }

    return 0;
}