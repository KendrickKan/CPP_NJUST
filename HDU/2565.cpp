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
    int n;
    while (t--)
    {
        cin >> n;
        n /= 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                cout << ' ';
            cout << 'X';
            for (int j = 0; j < 2 * (n - i) - 1; j++)
                cout << ' ';
            cout << 'X';
            cout << endl;
        }
        for (int i = 0; i < n; i++)
            cout << ' ';
        cout << 'X' << endl;
        for (int i = n - 1; i > -1; i--)
        {
            for (int j = 0; j < i; j++)
                cout << ' ';
            cout << 'X';
            for (int j = 0; j < 2 * (n - i) - 1; j++)
                cout << ' ';
            cout << 'X';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}