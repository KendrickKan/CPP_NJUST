/*
 * @Author: KendrickKan
 * @Date: 2020-09-26 19:14:43
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-09-26 20:34:33
 */
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
        int x, n, s, l, r;
        cin >> x >> n >> s >> l >> r;
        int cnt = 0;
        if (l <= r)
        {
            if (s >= l && s <= r)
                cout << 0 << endl;
            else
            {
                if (n % x == 0 && x > (r - l + 1))
                    cout << -1 << endl;
                else
                {
                    if (x <= (l - r + 1))
                    {
                        if (s > r)
                            cout << (n - s - 1 + l) % x + 1;
                        else
                            cout << (l - s - 1) % x + 1;
                    }
                    else
                    {
                        if (s > r)
                        {
                        }
                        else
                        {
                            
                        }
                    }
                }
            }
        }
        else if (l > r)
        {
            if ((s >= l && s <= (n - 1)) || (s >= 0 && s <= r))
                cout << 0 << endl;
            else
            {
                if (n % x == 0)
                    cout << -1 << endl;
                else
                {
                    while (s > r && s < l)
                    {
                        cnt++;
                        s += x;
                        s %= n;
                    }
                    cout << cnt << endl;
                }
            }
        }
    }
    return 0;
}