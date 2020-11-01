#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[1005];
    int maxlength[1005];
    memset(a, 0, sizeof(a));
    memset(maxlength, 0, sizeof(maxlength));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    maxlength[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int x = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                x = maxlength[j];
        }
        maxlength[i] = x + 1;
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
        if (maxlength[i] > ans)
            ans = maxlength[i];
    cout << ans << endl;
    return 0;
}