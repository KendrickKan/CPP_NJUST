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
pair<int, int> pa[100000];
string xx[100000];
int changestringtonum(string str)
{
    int num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        num = num * 10 + str[i] - '0';
    }
    return num;
}
int main()
{
    FastIO;
    mem0(pa);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string str;
        if (n == 1)
            cin >> str;
        else
            while (n--)
            {
                cin >> str;
                pa[changestringtonum(str)].first = 1;
            }
    }
    cin >> t;
    bool flag = false;
    int nummm = 0;
    while (t--)
    {
        string str;
        cin >> str;
        int x = changestringtonum(str);
        if (pa[changestringtonum(str)].first == 0 && pa[changestringtonum(str)].second == 0)
        {
            flag = true;
            xx[nummm] = str;
            nummm++;
            pa[changestringtonum(str)].second = 1;
        }
    }
    if (!flag)
        cout << "No one is handsome";
    else
    {
        rep(i, 0, nummm - 1)
        {
            cout << xx[i] << " ";
        }
        cout << xx[nummm - 1] << endl;
    }
    return 0;
}