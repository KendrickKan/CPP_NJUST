#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    int r, s, p, x, y, ans;
    while (cin >> r >> s >> p)
    {
        v.clear();
        for (int i = 0; i < p; i++)
        {
            cin >> x >> y;
            x = r - x + 1;
            if (y > s)
            {
                y -= s;
            }
            else
            {
                y = s - y + 1;
            }
            v.push_back(x + y);
        }
        sort(v.begin(), v.end());
        ans = 0;
        for (int i = 0; i < p; i++)
        {
            ans = max(ans, v[i] + p - i - 1);
        }
        cout << ans << endl;
    }
    return 0;
}