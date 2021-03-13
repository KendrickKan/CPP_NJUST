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
bool check1(int n)
{
    string x = to_string(n);
    if (x[0] == x[7] && x[1] == x[6] && x[2] == x[5] && x[3] == x[4])
        return true;
    else
        return false;
}
bool check2(int n)
{
    string x = to_string(n);
    if (x[0] == x[7] && x[1] == x[6] && x[2] == x[5] && x[3] == x[4] && x[0] == x[2] && x[1] == x[3] && x[0] != x[1])
        return true;
    else
        return false;
}
bool judgerun(int n)
{
    n %= 10000;
    return (n % 100 != 0 && n % 4 == 0) || (n % 400 == 0);
}
bool check3(int n)
{
    string x = to_string(n);
    if (x[4] >= '1' && x[5] > '2')
        return false;
    else
    {
        if ((x[4] == '0' && (x[5] == '1' || x[5] == '3' || x[5] == '5' || x[5] == '7' || x[5] == '8')) || (x[4] == '1' && (x[5] == '0' || x[5] == '2')))
        {
            if (x[6] > '3')
                return false;
            if (x[6] == '3' && x[7] > '1')
                return false;
            return true;
        }
        else if ((x[4] == '0' && (x[5] == '4' || x[5] == '6' || x[5] == '9')) || (x[4] == '1' && (x[5] == '1')))
        {
            if (x[6] > '3')
                return false;
            if (x[6] == '3' && x[7] > '0')
                return false;
            return true;
        }
        else if (x[4] == '0' && (x[5] == '2'))
        {
            int nian = n % 10000;
            if (judgerun(nian))
            {
                if (x[6] >= '3')
                    return false;
                else
                    return true;
            }
            else
            {
                if ((x[6] == '2' && x[7] == '9') || x[6] >= '3')
                    return false;
                else
                    return true;
            }
        }
        else
            return false;
    }
}
int main()
{
    FastIO;
    int n;
    read(n);
    n++;
    while (!(check1(n) && check3(n)))
        n++;
    cout << n << endl;
    while (!(check2(n) && check3(n)))
        n++;
    cout << n << endl;
    return 0;
}