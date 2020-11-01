#include <bits/stdc++.h>
using namespace std;
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