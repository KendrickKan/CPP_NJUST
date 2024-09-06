#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n, k ,M;
int num[10000];
int sum[1000][1000];
int dp[1000][1000];
int main()
{
	cin >> M;
	
	for (int m = M; m > 0; m--)
	{
       cin >> n;
	   cin >> k;
	   for (int i = 0; i < n; i++)
	   {
		   cin >> num[i];
	   }


	   for (int i = 0; i < n; i++)
	   {
		   int temp = 0;
		   for (int j = i; j < n; j++)
		   {
			   temp += num[j];
			   sum[i][j] += temp;
		   }
	   }


	   for (int i = 0; i < n; i++)
		   dp[i][0] = sum[0][i];

	   for (int i = 0; i < n; i++)
		   for (int j =1; j < k + 1 && j <= i; j++)
			   for (int p = 0; p < i; p++)
				   dp[i][j] = max(dp[p][j- 1] * sum[p+1][i], dp[i][j]);
	   cout << dp[n - 1][k] << endl;
	}
	return 0;
}