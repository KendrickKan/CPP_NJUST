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
    int x, y;
    cin >> x >> y;
    int t;
    cin >> t;
    int jia, yi;
    jia = yi = 0;
    while (t-- && jia <= x && yi <= y)
    {
        int a, a1, b, b1;
        cin >> a >> a1 >> b >> b1;
        int num = a + b;
        if (a1 != b1)
        {
            if (a1 == num)
                jia++;
            else if (b1 == num)
                yi++;
        }
    }
    if (jia == (x + 1))
        cout << "A" << endl
             << yi;
    else
        cout << "B" << endl
             << jia;
    return 0;
}