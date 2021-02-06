#include <bits/stdc++.h>
using namespace std;
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
struct node
{
    int a, b, c;
};
vector<node> ans;
int num[9];
int a, b, c;
void check()
{
    int x, y, z;
    x = num[0] * 100 + num[1] * 10 + num[2];
    y = num[3] * 100 + num[4] * 10 + num[5];
    z = num[6] * 100 + num[7] * 10 + num[8];
    if (x * b == y * a && c * y == z * b && c * x == z * a)
    {
        node temp;
        temp.a = x;
        temp.b = y;
        temp.c = z;
        ans.push_back(temp);
    }
}
bool cmp(node a, node b)
{
    return a.a < b.a;
}
int main()
{
    FastIO;
    cin >> a >> b >> c;
    rep(i, 0, 9)
    {
        num[i] = i + 1;
    }
    do
    {
        check();
    } while (next_permutation(num, num + 9));
    if (ans.size() == 0)
        cout << "No!!!" << endl;
    else
    {
        rep(i, 0, ans.size())
        {
            cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << endl;
        }
    }
    return 0;
}