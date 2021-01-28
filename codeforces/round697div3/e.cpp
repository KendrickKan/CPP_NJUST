/*
 * @Author: KendrickKan 
 * @Date: 2021-01-28 21:47:55 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-01-28 22:18:38
 */
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
const int MOD = 1e9 + 7;
//INT_MAX <limits>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[1001];
vector<int> nPrime(int n)
{
    int k = 2;
    vector<int> v;
    while (k <= n)
    {
        bool isPrime = true;
        int t = sqrt(k);
        for (; t > 1; t--)
        {
            if (k % t == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            v.push_back(k);
        k++;
    }
    return v;
}
//计算n!中素数m的次数
int dPrime(int n, int m)
{
    int pow = 0;
    while (n >= m)
    {
        int temp = n / m;
        pow += temp;
        n = temp;
    }
    return pow;
}
int kc(int n, int m)
{
    long long ans = 1;
    vector<int> v = nPrime(n);
    for (int i = 0; i < v.size(); i++)
    {
        int k = v.at(i), pow;
        pow = dPrime(n, k) - dPrime(m, k) - dPrime(n - m, k);
        for (int j = 0; j < pow; j++)
        {
            ans *= k;
            ans %= (int)(1e9 + 7);
        }
    }
    return (int)ans;
}
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        mem0(a);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        int tt = 1;
        int minnum = 0, maxnum = n;
        for (int i = k - 2; i >= 0; i--)
        {
            if (a[i] == a[k - 1])
            {
                tt++;
            }
            else
            {
                minnum = i + 1;
                break;
            }
        }
        for (int i = k; i < n; i++)
        {
            if (a[i] == a[k - 1])
                tt++;
            else
            {
                maxnum = i;
                break;
            }
        }
        //cout << kc(4, 1);
        cout << kc(tt, k - minnum) << endl;
    }
    return 0;
}