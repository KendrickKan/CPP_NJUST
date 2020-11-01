#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    vector< pair<int, int> > veca, vecb;
    for (int i = 0; i < a; i++)
    {
        int x, y;
        cin >> x >> y;
        veca.push_back(make_pair(x, y));
    }
    for (int i = 0; i < b; i++)
    {
        int x, y;
        cin >> x >> y;
        vecb.push_back(make_pair(x, y));
    }
    int i = 0, j = 0;
    while (i < a && j < b)
    {
        if (veca[i].first == vecb[j].first)
        {
            ans += veca[i].second * vecb[j].second;
            i++;
            j++;
        }
        else if (veca[i].first < vecb[j].first)
            i++;
        else
            j++;
    }
    cout << ans;

    return 0;
}