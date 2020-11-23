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
    getline(cin, str);
    string t;
    cin >> t;
    int a[26];
    mem0(a);
    rep(i, 0, t.length())
    {
        a[t[i] - 'a']++;
    }
    rep(i, 0, str.length())
    {
        if ((str[i] - 'a') >= 0 && (str[i] - 'a') < 26)
        {
            if (a[str[i] - 'a'] == 0)
                cout << str[i];
        }
        else
            cout << str[i];
    }
    return 0;
}