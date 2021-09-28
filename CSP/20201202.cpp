#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fo(x) for (register int i = 1; i <= x; ++i)
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
template <typename T>
void read(T &t)
{
    t = 0;
    char ch = getchar();
    int f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    do
    {
        (t *= 10) += ch - '0';
        ch = getchar();
    } while ('0' <= ch && ch <= '9');
    t *= f;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool cmp(pii a, pii b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;

    // if (a.first != b.first)
    //     return a.first < b.first;
    // return a.second < b.second;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<pii> vec;
    int num = 0;
    int ans;
    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        if (y == 1)
            num++;
        vec.pb(make_pair(x, y));
    }
    sort(vec.begin(), vec.end(), cmp);
    ans = vec[0].first;
    int pres = 0;
    rep(i, 1, n)
    {
        if (vec[i - 1].second == 0 && vec[i].first != vec[i - 1].first)
        {
            num += i - pres;
            pres = i;
            ans = vec[i].first;
        }
        else if (vec[i - 1].second == 0 && vec[i].first == vec[i - 1].first)
        {
        }
        else if (vec[i - 1].second == 1 && vec[i].first == vec[i - 1].first)
        {
            num -= i - pres;
            pres = i;
        }
        else
            ans = vec[i].first;
    }
    cout << ans;
    return 0;
}