#include <bits/stdc++.h>
using namespace std;
int miles[1005];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)

    {
        int n, x, y;
        cin >> n >> x >> y;
        int sum = 0;
        memset(miles, 0, sizeof(miles));
        int x1, y1;
        int i = 1;
        x1 = i * x;
        for (i = 1; x1 < n; i++)
        {
            miles[x1] = 1;
            x1 = i * x;
        }
        i = 1;
        y1 = i * y;
        for (i = 1; y1 < n; i++)
        {
            miles[y1] = 1;
            y1 = i * y;
        }
        for (i = 0; i < n; i++)
            if (miles[i] == 1)
                sum++;
        cout<<n<<' '<<x<<' '<<y<<endl;
        cout << sum<<endl;
    }
    return 0;
}