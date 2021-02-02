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
int main()
{
    FastIO;
    string str;
    cin >> str;
    int x = (str[0] - '0') * 1;
    x += (str[2] - '0') * 2;
    x += (str[3] - '0') * 3;
    x += (str[4] - '0') * 4;
    x += (str[6] - '0') * 5;
    x += (str[7] - '0') * 6;
    x += (str[8] - '0') * 7;
    x += (str[9] - '0') * 8;
    x += (str[10] - '0') * 9;
    x %= 11;
    if ((x == (str[12] - '0') && x != 10) || (x == 10 && str[12] == 'X'))
        cout << "Right" << endl;
    else
    {
        rep(i, 0, str.length() - 1)
        {
            cout << str[i];
        }
        if (x == 10)
            cout << 'X' << endl;
        else
            cout << x << endl;
    }
    return 0;
}