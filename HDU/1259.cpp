#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int a[7] = {1, 2, 3, 4, 5, 6};
        int n;
        cin >> n;
        int temp, x, y;
        while (n--)
        {
            cin >> x >> y;
            temp = a[x - 1];
            a[x - 1] = a[y - 1];
            a[y - 1] = temp;
        }
        for (int i = 0; i < 7; i++)
            if (a[i] == 2)
            {
                cout << i + 1 << endl;
                break;
            }
    }

    return 0;
}