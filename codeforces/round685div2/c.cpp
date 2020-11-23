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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a;
        cin >> b;
        int anum[26];
        int bnum[26];
        mem0(anum);
        mem0(bnum);
        rep(i, 0, n)
        {
            anum[a[i] - 'a']++;
            anum[b[i] - 'a']--;
        }
        bool flag = true;
        rep(i, 0, 25)
        {
            while (anum[i] >= k)
            {
                anum[i] -= k;
                anum[i + 1] += k;
            }
            if (anum[i] < 0)
            {
                flag = false;
                break;
            }
        }
        if (anum[25] < 0)
            flag = false;
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}