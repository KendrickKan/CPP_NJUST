#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;
const int maxn = 10005;
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, r;
        cin >> n >> r;
        vector<pair<ll, ll>> vec;
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            pair<ll, ll> p;
            p.first = x;
            p.second = y;
            if (i == 0)
            {
                vec.push_back(p);
                cout << "Yes" << endl;
            }
            else
            {
                bool flag = false;
                for (int j = 0; j < vec.size(); j++)
                {
                    if (r * r * 4 > ((x - vec[j].first) * (x - vec[j].first) + (y - vec[j].second) * (y - vec[j].second)))
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    cout << "No" << endl;
                else
                {
                    vec.push_back(p);
                    cout << "Yes" << endl;
                }
            }
        }
    }
    return 0;
}
