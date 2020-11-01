/*
 * @Author: KendrickKan 
 * @Date: 2020-09-27 09:44:54 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-09-27 10:28:02
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll KMOD = 1e9 + 7;

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

//计算组合数C(n,m)
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, n;
    cin >> k >> n;
    int gnum = 0, pnum = 0;
    ll cnt = 0;
    for (int gnum = 0; gnum <= n; gnum++)
    {
        if ((n - gnum) % k != 0)
            continue;
        else
        {
            pnum = (n - gnum) / k;
            if (pnum > (gnum + 1))
                continue;
            else
            {
                ll x = kc(gnum + 1, pnum);
                x %= KMOD;
                cnt += x;
                cnt %= KMOD;
            }
        }
    }
    cout << cnt % KMOD;
    return 0;
}