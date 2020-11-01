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
        int n;
        cin >> n;
        int a[105];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = n - 1; i > 0; i--)
        {
            cout << a[i] << ' ';
        }
        cout << a[0] << endl;
    }

    return 0;
}