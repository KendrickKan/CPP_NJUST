#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
const int MAXN=50005;
int dp[MAXN];
int main()
{
    FastIO;
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		dp[0]=1;
		for(int i=1;i<str.size();i++)
		{
			if(i%2==0) dp[i]=dp[i-1];
			else{
				if(str[i]==str[i/2])
				{
					dp[i]=dp[i-1]+1;
				}
				else{
					dp[i]=dp[i-1];
				}
			}
		}
		for(int i=0;i<str.size()-1;i++)
			cout<<dp[i]<<" ";
			cout<<dp[str.size()-1];
			cout<<endl;
		}
    return 0;
}
