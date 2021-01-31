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
//pii p[1000005];
int main()
{
    FastIO;
    vector<pii> p;
    for (int i = 0; i < 1000005; i++)
    {
        pii temp;
        temp.first = i;
        temp.second = 1000000;
        p.push_back(temp);
    }
    int num = 2;
    p[1].second = 1;
    p[0].first = -1;
    p[0].second = 1;
    for (int i = 1; i < 1000005;)
    {
        int maxnum = -1;
        for (int j = i; j >= i - num - 1 && j >= 0; j--)
        {
            //cout << p[j].first + num << endl;
            if (p[j].first + num > maxnum && p[j].second != 1000000)
                maxnum = p[j].first + num;
            if (p[p[j].first + num].second > num && p[j].second != 1000000)
                p[p[j].first + num].second = num;
        }
        i = maxnum;
        num++;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << p[x].second << endl;
    }
    return 0;
}