//TLE
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
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> vec;
    int nowmaxloc = 0;
    int tempmaxloc = 0;
    for (int i = 0; i < n; i++)
    {
        int a, x;
        scanf("%d%d", &a, &x);
        if (a == 1)
        {
            vec.pb(x);
            sort(vec.begin(), vec.end());
            vector<int>::iterator newit = unique(vec.begin(), vec.end());
            vec.erase(newit, vec.end());
        }
        else
        {
            tempmaxloc = nowmaxloc;
            int neednum = nowmaxloc + 1;
            for (int j = nowmaxloc; j < vec.size();)
            {
                if (vec[j] == neednum)
                {
                    nowmaxloc = j + 1;
                    tempmaxloc = j + 1;
                    neednum++;
                    j++;
                }
                else
                {
                    if (neednum == x)
                    {
                        nowmaxloc = j;
                        neednum++;
                    }
                    else
                        break;
                }
            }
            if (nowmaxloc + 1 == x)
                tempmaxloc = nowmaxloc + 1;
            printf("%d\n", max(nowmaxloc, tempmaxloc) + 1);
        }
    }

    return 0;
}