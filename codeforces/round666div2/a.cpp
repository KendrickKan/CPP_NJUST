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
        string a[1005];
        int b[26];
        memset(b, 0, sizeof(b));
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            a[i] = x;
            for (int j = 0; j < a[i].length(); j++)
            {
                b[a[i][j] - 'a']++;
            }
        }
        int flag = 1;
        for (int i = 0; i < 26; i++)
            if (b[i] % n != 0)
            {
                flag = 0;
                break;
            }
        if (flag)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}