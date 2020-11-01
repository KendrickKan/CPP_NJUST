#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
bool cmp(ll a, ll b)
{
    return a > b;
}
int main()
{
    IOS;
    ll n, d, m;
    cin >> n >> d >> m;
    ll a[30];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, cmp);
    int x = -1;
    for (int i = 0; i < n; i++)
        if (a[i] < m)
        {
            x = i - 1;
            break;
        }
    ll ans = 0;
    int beginnum = 0, endnum = n - 1, midnum = x;
    for (int i = 0; i < n; i++)
    {
        if (beginnum <= x && (endnum >= (midnum + d)))
        {
            ll y = 0;
            for (int j = 1; j <= d; j++)
                y += a[midnum + j];
            if (a[beginnum] > y)
            {
                ans += a[beginnum];
                for (int j = 0; j < d; j++)
                    a[endnum - j] = 0;
                endnum -= d;
                i += (d - 1);
                beginnum++;
            }
            else
            {
                ans += y;
                for (int j = 0; j < d; j++)
                    a[midnum + j] = 0;
                sort(a, a + n, cmp);
                i += (d - 1);
                endnum -= d;
            }
        }
        else if (beginnum > x)
        {
            ans += a[beginnum];
            beginnum++;
        }
        else if (beginnum <= x && endnum > midnum && endnum < (midnum + d))
        {
            ll y = 0;
            for (int j = 1; j <= (endnum - midnum); j++)
                y += a[midnum + j];
            if (a[beginnum] > y)
            {
                ans += a[beginnum];
                for (int j = endnum; j > midnum; j--)
                    ans += a[endnum];
                for (int j = 0; j < d; j++)
                    a[endnum - j] = 0;
                endnum -= d;
                beginnum++;
                i += (d - 1);
            }
            else
            {
                ans += y;
                for (int j = 0; j < d; j++)
                    a[midnum + j] = 0;
                sort(a, a + n, cmp);
                endnum -= (endnum - midnum);
                i += (endnum - midnum);
            }
        }
        else
        {
            ans += a[beginnum];
            beginnum++;
            i += (d - 1);
        }
    }
    cout << ans;
    return 0;
}