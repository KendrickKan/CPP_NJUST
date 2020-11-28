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
char ch[1005][1005];
int main()
{
    FastIO;
    int n;
    cin >> n;
    memset(ch, '-', sizeof(ch));
    //getchar();
    string ttt;
    getline(cin, ttt);
    string str;
    getline(cin, str);
    int x = ceil(str.length() * 1.0 / n );
    int y = str.length() % n;
    int t = 0;
    for (int j = 1004; j > 1004 - x; j--)
    {
        for (int i = 0; i < n; i++)
        {
            ch[i][j] = str[t];
            t++;
            if (t == str.length())
                goto stop;
        }
    }
stop:;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1005 - x; j < 1005; j++)
        {
            if (ch[i][j] == '-')
                cout << ' ';
            else
                cout << ch[i][j];
        }
        cout << endl;
    }
    return 0;
}