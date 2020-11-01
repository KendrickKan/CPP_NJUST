#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n && n)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
            {
                for (int i = 1; i <= n; i++)
                    cout << setw(3) << i;
                cout << endl;
            }
            else if (j == n)
            {
                for (int i = 1; i <= n; i++)
                    cout << setw(3) << 3 * n - 1 - i;
                cout << endl;
            }
            else
            {
                cout << setw(3) << 4 * n - 2 - j;
                for (int i = 1; i <= n - 2; i++)
                    cout << "   ";
                cout << setw(3) << n + j - 1;
                cout << endl;
            }
        }
    }

    return 0;
}