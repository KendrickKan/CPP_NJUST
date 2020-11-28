//ctrl alt i new-head
#include <bits/stdc++.h>
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
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
string changenumtostr(int n)
{
    string str;
    while (n > 0)
    {
        str += n % 10 + '0';
        n /= 10;
    }
    int temp=str.length();
    for (int i = 0; i < 4 - temp; i++)
        str += '0';
    str.reserve();
    return str;
}
int judge(string str)
{
    set<int> se;
    for (int i = 0; i < str.length(); i++)
    {
        se.insert(str[i] - '0');
    }
    return se.size();
}
int main()
{
    FastIO;
    int y, n;
    cin >> y;
    cin >> n;
    string str = changenumtostr(y);
    bool flag = true;
    int i = 0;
    while (flag)
    {
        if (judge(str) == n)
        {
            flag = false;
            cout << i << " ";
            for (int x = str.length() - 1; x >= 0; x--)
            {
                cout << str[x];
            }
            cout << endl;
        }
        else
        {
            y++;
            i++;
            str = changenumtostr(y);
        }
    }
    return 0;
}