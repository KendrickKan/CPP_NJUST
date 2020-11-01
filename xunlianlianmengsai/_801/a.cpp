#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5;
priority_queue<ll> q1, q2;
char s[MAXN];
int main()
{
    ll n, l;
    scanf("%lld", &n);
    getchar();
    for (ll q = 1; q <= 2 * n; q++)
    {
        scanf("%s", s + 1);
        l = strlen(s + 1);
        int num = l;
        for (ll i = 1; i <= l / 2; i++)
        {
            if (l % i)
                continue;
            bool flag = true;
            for (ll j = 1; j <= l; j++)
            {
                if (s[j] != s[(j - 1) % i + 1])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                num = i;
                break;
            }
        }
        if (q <= n)
            q1.push(num);
        else
        {
            q2.push(num);
        }
    }
    ll sum = 0;
    while (!q1.empty())
    {
        ll a = q1.top();
        ll b = q2.top();
        sum += (a - b) * (a - b);
        q1.pop();
        q2.pop();
    }
    cout << sum << endl;
}
