#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
void solve(int n)
{
    int people = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 1)
        {
            if (people == 1)
            {
                cout << "First" << endl;
                return;
            }
            else
            {
                cout << "Second" << endl;
                return;
            }
        }
        if (a[i] == 1)
        {
            if (people == 1)
                people = 2;
            else
            {
                people = 1;
            }
        }
    }
    if (people == 1)
        cout << "Second" << endl;
    else
    {
        cout << "First" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        solve(n);
    }

    return 0;
}
