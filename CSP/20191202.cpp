//ctrl alt i new-head
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem0(a) memset(a, 0, sizeof(a))
#define memfu1(a) memset(a, -1, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define EPS 1e-10
const int MOD = 1e9 + 7;
//INT_MAX <limits>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pii p[1005];
int main()
{
    FastIO;
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        cin >> p[i].first >> p[i].second;
    }
    int num[5] = {0};
    rep(i, 0, t)
    {
        int n = 0;
        int cnt = 0;
        rep(j, 0, t)
        {
            if (p[i].first == p[j].first && p[i].second == p[j].second + 1)
                cnt++;
            if (p[i].first == p[j].first && p[i].second == p[j].second - 1)
                cnt++;
            if (p[i].first == p[j].first + 1 && p[i].second == p[j].second)
                cnt++;
            if (p[i].first == p[j].first - 1 && p[i].second == p[j].second)
                cnt++;
            if (p[i].first == p[j].first + 1 && p[i].second == p[j].second + 1)
                n++;
            if (p[i].first == p[j].first - 1 && p[i].second == p[j].second + 1)
                n++;
            if (p[i].first == p[j].first - 1 && p[i].second == p[j].second - 1)
                n++;
            if (p[i].first == p[j].first + 1 && p[i].second == p[j].second - 1)
                n++;
        }
        if (cnt == 4)
            num[n]++;
    }
    rep(i, 0, 5)
    {
        cout << num[i] << endl;
    }
    return 0;
}