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
    int a[4];
    mem0(a);
    char p[4] = {'G', 'P', 'L', 'T'};
    rep(i, 0, str.length())
    {
        if (str[i] == 'G' || str[i] == 'g')
            a[0]++;
        else if (str[i] == 'P' || str[i] == 'p')
            a[1]++;
        else if (str[i] == 'L' || str[i] == 'l')
            a[2]++;
        else if (str[i] == 'T' || str[i] == 't')
            a[3]++;
    }
    int x = 0;
    while (a[0] != 0 || a[1] != 0 || a[2] != 0 || a[3] != 0)
    {
        if (a[x % 4] > 0)
        {
            cout << p[x % 4];
            a[x % 4]--;
        }
        x++;
    }
    return 0;
}