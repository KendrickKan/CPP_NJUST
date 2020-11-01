#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*int D(int a[], int i)
{
    if (i == 0 || i == 1)
        return 1;
    else
    {
        int b[26];
        memset(b, 0, sizeof(b));
        for (int j = 0; j < 26; j++)
        {
            b[a[i] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans += b[i] / 2;
        }
        return D(b, ans) + 1;
    }
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        string str;
        cin >> str;
        int a[26];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < str.length(); i++)
        {
            a[str[i] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] > ans)
                ans = a[i];
        }
        cout << "Case #" << x << ": " << ans << endl;
    }
    return 0;
}