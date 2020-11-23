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
int main()
{
    FastIO;
    string str;
    cin >> str;
    if (str[0] == '0' || (str[0] == '1' && str[1] == '0') || (str[0] == '1' && str[1] == '1'))
        cout << "Only " << str << ".  Too early to Dang.";
    else
    {
        int num = 0;
        num = (str[0] - '0') * 10 + str[1] - '0';
        num %= 12;
        if (str[3] == '0' && str[4] == '0')
        {
            if (num == 0)
            {
                cout << "Only " << str << ".  Too early to Dang.";
            }
            else
            {
                rep(i, 0, num)
                {
                    cout << "Dang";
                }
            }
        }
        else
        {
            rep(i, 0, num + 1)
            {
                cout << "Dang";
            }
        }
    }

    return 0;
}