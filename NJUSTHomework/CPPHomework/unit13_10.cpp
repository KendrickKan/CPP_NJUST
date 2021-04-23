/*
 * @Author: KendrickKan 
 * @Date: 2020-11-01 19:03:31 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-11-06 19:46:16
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
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename T>
vector<T> nPrime(T n)
{
    T k = 2;
    vector<T> v;
    while (k <= n)
    {
        bool isPrime = true;
        T t = sqrt(k);
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
template<typename T>
//计算n!中素数m的次数
T dPrime(T n, T m)
{
    T pow = 0;
    while (n >= m)
    {
        T temp = n / m;
        pow += temp;
        n = temp;
    }
    return pow;
}
template<typename T>
//计算组合数C(n,m)
T kc(T n, T m)
{
    T ans = 1;
    vector<T> v = nPrime(n);
    for (T i = 0; i < v.size(); i++)
    {
        T k = v.at(i);
        T pow;
        pow = dPrime(n, k) - dPrime(m, k) - dPrime(n - m, k);
        for (T j = 0; j < pow; j++)
        {
            ans *= k;
            //ans %= (int)(1e9 + 7);
        }
    }
    return (T)ans;
}
int main()
{
    FastIO;
    int a=24, b=4;
    cout<<kc(a,b);
    return 0;
}