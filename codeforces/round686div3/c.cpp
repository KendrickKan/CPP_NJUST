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
int a[200005];
int b[200005];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        mem0(a);
        mem0(b);
        set<int> se;
        int n;
        cin >> n;
        int x;
        cin >> x;
        b[x]++;
        se.insert(x);
        int num = 0;
        a[num] = x;
        num++;
        int qian = x;
        rep(i, 1, n)
        {
            int x;
            cin >> x;
            if (x != qian)
            {
                b[x]++;
                se.insert(x);
                a[num] = x;
                num++;
                qian = x;
            }
        }
        int minnum = 200005;
        int minnumm;
        for (int i = 0; i < 200005; i++)
        {
            if (b[i] < minnum && b[i] != 0)
            {
                minnum = b[i];
                minnumm = i;
            }
        }
        int ans = 1;
        for (int i = 0; i < num; i++)
        {
            if (a[i] == minnumm && i != 0 && i != (num - 1))
                ans++;
        }
        int ans1 = 1;
        int ans2 = 1;
        for (int i = 0; i < num; i++)
        {
            if (a[i] == a[0] && i != 0 && i != (num - 1))
                ans1++;
        }
        for (int i = 0; i < num; i++)
        {
            if (a[i] == a[num - 1] && i != 0 && i != (num - 1))
                ans2++;
        }
        int ans3 = 200005;
        bool flag = false;
        for (int i = 1; i < num; i++)
        {
            if (a[i] != a[0])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            ans3 = 0;
        cout << min(ans, min(ans1, min(ans2, ans3))) << endl;
    }
    return 0;
}