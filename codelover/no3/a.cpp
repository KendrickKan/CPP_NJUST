/*
 * @Author: KendrickKan 
 * @Date: 2021-02-02 21:21:03 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-02-02 21:29:20
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
bool isPrime(int t)
{
    if (t == 1 || t == 0)
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
    string str;
    cin >> str;
    int a[26];
    mem0(a);
    rep(i, 0, str.length())
    {
        a[str[i] - 'a']++;
    }
    int minnum = 1000;
    int maxnum = 0;
    rep(i, 0, 26)
    {
        if (a[i] < minnum && a[i])
            minnum = a[i];
        if (a[i] > maxnum)
            maxnum = a[i];
    }
    if (isPrime(maxnum - minnum))
        cout << "Lucky Word\n"
             << maxnum - minnum;
    else
        cout << "No Answer\n0";
    return 0;
}