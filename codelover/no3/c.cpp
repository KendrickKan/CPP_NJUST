/*
 * @Author: KendrickKan 
 * @Date: 2021-02-02 21:31:41 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-02-02 21:47:28
 */
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
    string a;
    getline(cin, a);
    string b;
    getline(cin, b);
    rep(i, 0, a.length())
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] += 32;
        }
    }
    rep(i, 0, b.length())
    {
        if (b[i] >= 'A' && b[i] <= 'Z')
        {
            b[i] += 32;
        }
    }
    a = ' ' + a + ' ';
    b = ' ' + b + ' ';
    if (b.find(a) == string::npos)
    {
        cout << -1 << endl;
    }
    else
    {
        int alpha = b.find(a);
        int beta = b.find(a), s = 0;
        while (beta != string::npos)
        {
            ++s;
            beta = b.find(a, beta + 1);
        }
        cout << s << " " << alpha << endl;
    }
    return 0;
}