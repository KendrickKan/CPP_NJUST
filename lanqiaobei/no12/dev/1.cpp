#include<bits/stdc++.h>
using namespace std;
#define long long ll
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int a[10];
int main()
{
	FastIO;
	for(int i = 0; i <= 9; i++ )
	{
		a[i]= 2021;
	}
	int ans = 0;
	int t = 1;
	while(1)
	{
		int temp = t;
		while(temp>0)
		{
			int ktemp = temp%10;
			temp/=10;
			if(a[ktemp]<=0)
				goto stop;
			else a[ktemp]--;
		}
		ans++;
		t++;
	}
	stop:
		cout<<ans<<endl;
	return 0;
}
