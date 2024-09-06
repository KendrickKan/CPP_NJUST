#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// ����С�ڵ���N����������
vector<int> generatePrimes(int n)
{
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] =0;
    for (int i = 2; i <= sqrt(n); i++) 
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
     return isPrime;
}

int countPrimeSum(int n) {
    // ������������
    vector<int> primes = generatePrimes(n);
    // ��ʼ��dp����
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    //dp���鸳ֵ
    for (int i = 2; i <= n; i++)
    {
        //i������
        if (primes[i])
        {
            //jΪj-i����+����i
            for (int j = i; j <= n; j++)
            {
                dp[j] += dp[j - i];
            }
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countPrimeSum(n) << endl;
    return 0;
}
