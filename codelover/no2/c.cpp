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
bool checkwei(int a)
{
    if ((1000 <= a && a <= 9999) || (100000 <= a && a <= 999999))
        return false;
    return true;
}
bool checkhuiwen(int a)
{
    string str = "";
    while (a > 0)
    {
        str += '0' + a % 10;
        a /= 10;
    }
    reverse(str.begin(), str.end());
    rep(i, 0, str.length() / 2 + 1)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}
bool isPrime(int t)
{
    if (t == 1)
        return false;
    for (int i = 2; i <= sqrt(t); i++)
    {
        if (t % i == 0)
            return false;
    }
    return true;
}
int main()
{
    FastIO;
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0)
        a++;
    b = min(9999999, b);
    for (int i = a; i <= b; i += 2)
    {
        if (checkwei(i))
            if (checkhuiwen(i))
                if (isPrime(i))
                    cout << i << endl;
    }
    return 0;
}