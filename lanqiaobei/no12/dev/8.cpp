#include<bits/stdc++.h>
using namespace std;
#define long long ll
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int main()
{
	FastIO;
	string str;
	cin>>str;
	stack<int> sta;
	for(int i = 0 ;i<str.length();i++)
	{
		if(str[i]=='(')
			sta.push(1);
	}
	return 0;
}
