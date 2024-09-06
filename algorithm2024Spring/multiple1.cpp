#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n, k ,M;
long long num[100];
long long sum[100][100];
long long dp[100][100];
long long main()
{
	cin >> M;
	
	for (int m = M; m > 0; m--)
	{
		memset(num, 0, sizeof(num));
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
       cin >> n;
	   cin >> k;
	   for (int i = 0; i < n; i++)
	   {
		   cin >> num[i];
	   }


	   for (int i = 0; i < n; i++)
	   {
		   long long temp = 0;
		   for (int j = i; j < n; j++)
		   {
			   temp += num[j];
			   sum[i][j] = temp;
		   }
	   }


	   for (int i = 0; i < n; i++)
		   dp[i][0] = sum[0][i];

	   for (int i = 0; i < n; i++)
		   for (int j =1; j <= k && j <= i; j++)
			   for (int p = 0; p < i; p++)
				   dp[i][j] = max(dp[p][j- 1] * sum[p+1][i], dp[i][j]);
	   cout << dp[n - 1][k] << endl;
	}
	return 0;
}