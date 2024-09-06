#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
//埃氏筛法选出素数
//const int max = 10000;
bool prime[10000];
long dp[100];
void prime_judge(int n)
{
	memset(prime, 1, sizeof(prime));
	prime[0] = 0;
	prime[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (prime[i])
		{
			for (int j = 2 * i; j <= n; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}
int main()
{
	int n = 0;
	dp[0] = 1;
	cin >> n;
	prime_judge(n);
	for (int i = 2; i <= n; i++)
	{
		if (prime[i])
		{
			for (int m = i; m <=n; m++)
			{
				dp[m] += dp[m - i];
			}
		}
	}
	cout << dp[n];
	system("pause");
	return 0;
}