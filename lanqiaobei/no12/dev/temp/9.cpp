#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
const int MOD = 1e9+7;
int main()
{
	FastIO;
	string str;
	cin>>str;
	long long ans =1;
	for(int i =str.length();i>=1;i--)
	{
		ans*=i;
		ans%=MOD;
	}
	cout<<ans%MOD;
	return 0;
}
