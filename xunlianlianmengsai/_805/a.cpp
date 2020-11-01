#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int a[10005];
    while (cin >> n && n != 0)
    {
        memset(a, 0, sizeof(a));
        int sum = 0;
        int ave;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        ave = sum / n;
        sort(a, a + n, cmp);
        int x;
        for (int i = n - 1; i >= 0; i--)
            if (a[i] <= ave)
            {
                x = i;
                break;
            }
        cout << x + 1 << endl;
    }

    return 0;
}