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
        ll n;
        cin >> n;
        ll num = 1;
        int begin = 2;
        vector<ll> vec;
        while (n > begin)
        {
            for (int i = begin; i < n / 2 + 1; i++)
            {
                if (n % begin == 0)
                {
                    n /= begin;
                    begin = i;
                    vec.push_back(begin);
                    num++;
                    break;
                }
            }
        }
        cout << num << endl;
        if (num == 1)
        {
            cout << n;
        }
        else
        {
            for (int i = 0; i < num; i++)
            {
                cout << vec[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}