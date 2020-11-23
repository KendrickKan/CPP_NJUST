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
    int n;
    cin >> n;
    n--;
    ll fenzi = 0, fenmu = 0;
    string str;
    cin >> str;
    int x = str.find('/');
    bool iffu = false;
    int temp = 0;
    if (str[0] == '-')
    {
        iffu = true;
        temp = 1;
    }
    for (int i = temp; i < x; i++)
    {
        fenzi = str[i] - '0' + fenzi * 10;
    }
    if (iffu)
        fenzi *= -1;
    for (int i = x + 1; i < str.length(); i++)
    {
        fenmu = str[i] - '0' + fenmu * 10;
    }
    while (n--)
    {
        cin >> str;
        x = str.find('/');
        iffu = false;
        temp = 0;
        ll tempfenzi = 0, tempfenmu = 0;
        if (str[0] == '-')
        {
            iffu = true;
            temp = 1;
        }
        for (int i = temp; i < x; i++)
        {
            tempfenzi = str[i] - '0' + tempfenzi * 10;
        }
        if (iffu)
            tempfenzi *= -1;
        for (int i = x + 1; i < str.length(); i++)
        {
            tempfenmu = str[i] - '0' + tempfenmu * 10;
        }
        ll ll = fenmu * tempfenmu / __gcd(fenmu, tempfenmu);
        fenzi = fenzi * (ll / fenmu) + tempfenzi * (ll / tempfenmu);
        fenmu = ll;
        bool iffufu = false;
        if (fenzi < 0)
            iffufu = true;
        if (iffufu)
            fenzi *= -1;
        int maxgcd = __gcd(fenzi, fenmu);
        fenzi /= maxgcd;
        fenmu /= maxgcd;
        if (iffufu)
            fenzi *= -1;
    }
    if (fenzi == 0)
        cout << 0;
    else
    {
        if (fenzi > 0)
        {
            if (fenzi > fenmu)
            {
                if (fenzi % fenmu == 0)
                    cout << fenzi / fenmu;
                else
                {
                    cout << fenzi / fenmu << " " << fenzi % fenmu << '/' << fenmu;
                }
            }
            else if (fenzi == fenmu)
                cout << 1 << endl;
            else
                cout << fenzi << '/' << fenmu;
        }
        else
        {
            fenzi *= -1;
            if (fenzi > fenmu)
            {
                if (fenzi % fenmu == 0)
                    cout << '-' << fenzi / fenmu;
                else
                {
                    cout << '-' << fenzi / fenmu << " " << fenzi % fenmu << '/' << fenmu;
                }
            }
            else if (fenzi == fenmu)
                cout << '-' << 1 << endl;
            else
                cout << '-' << fenzi << '/' << fenmu;
        }
    }

    return 0;
}