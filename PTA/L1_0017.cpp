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
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main()
{
    FastIO;
    string str;
    cin >> str;
    bool iffu = false;
    if (str[0] == '-')
    {
        iffu = true;
    }
    int len = str.length() - (iffu ? 1 : 0);
    int twonum = 0;
    for (int i = iffu ? 1 : 0; i < str.length(); i++)
    {
        if (str[i] == '2')
        {
            twonum++;
        }
    }
    bool ifeven = false;
    if ((str[str.length() - 1] - '0') % 2 == 0)
        ifeven = true;
    double ans = twonum * 1.0 / len * (1.0 + (iffu ? 0.5 : 0)) * (ifeven ? 2.0 : 1.0) * 100;
    printf("%.2f%%",ans);
    return 0;
}