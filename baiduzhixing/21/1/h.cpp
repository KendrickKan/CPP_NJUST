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
int identity[55];
int li[55][55];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        mem0(identity);
        int langren;
        int num = n;
        for (int i = 1; i <= n; i++)
        {
            cin >> identity[i];
            if (identity[i] == 1)
                langren = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> li[i][j];
            }
        }
        bool flag = false; //langren huozhe
        int kiilp = li[langren][1];
        while (!flag && num > 2)
        {
            if (kiilp == langren)
                flag = true;
            else
            {
                identity[kiilp] = -1;
                for (int i = 1; i <= n; i++)
                {
                    if (identity[li[kiilp][i]] != -1)
                    {
                        kiilp = li[kiilp][i];
                        break;
                    }
                }
            }
            num--;
        }
        if (flag)
            cout << "lieren" << endl;
        else
            cout << "langren" << endl;
    }
    return 0;
}