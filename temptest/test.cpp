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
// INT_MAX <limits>
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
void printstring(char a[])
{
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    FastIO;
    string str1 = "KD is a PIG!";
    string str2 = "JZW HATE KD!!!!";
    while (0)
    {
        cout << str1 << " " << str2 << endl;
    }
    // cout << (str1 < str2) << endl;
    char _919106840420kandong[9] = {'k', 'a', 'n', 'd', 'o', 'n', 'g', 'k', 'k'};
    printstring(_919106840420kandong);
    return 0;
}