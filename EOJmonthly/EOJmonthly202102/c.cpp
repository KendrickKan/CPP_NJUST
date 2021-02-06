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
struct kquestion
{
    int qian, hou, num;
};
vector<kquestion> kq;
int vec[1000005];
bool check()
{
    rep(i, 0, kq.size())
    {
        bool flag = false;
        for (int j = kq[i].qian; j <= kq[i].hou; j++)
        {
            if (vec[j] < kq[i].num)
                return false;
            if (vec[j] == kq[i].num)
                flag = true;
        }
        if (!flag)
            return false;
    }
    return true;
}
int main()
{
    FastIO;
    int n, q;
    cin >> n >> q;
    // vec[0] = 1;
    // vec[1] = 4;
    // vec[2] = 3;
    // vec[3] = 0;
    // vec[4] = 2;
    rep(i, 0, n)
    {
        vec[i] = i;
    }
    rep(i, 0, q)
    {
        int x, y, z;
        cin >> x >> y >> z;
        kquestion temp;
        temp.qian = x;
        temp.hou = y;
        temp.num = z;
        kq.push_back(temp);
    }
    bool flag = false;
    do
    {
        if (check())
        {
            flag = true;
            break;
        }
    } while (next_permutation(vec, vec + n));
    if (flag)
    {
        rep(i, 0, n)
        {
            cout << vec[i] << " ";
        }
    }
    else
        rep(i, 0, n)
        {
            cout << -1 << " ";
        }
    return 0;
}