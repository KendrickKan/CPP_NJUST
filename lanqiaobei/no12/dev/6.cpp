#include<bits/stdc++.h>
using namespace std;
#define long long ll
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int t;
int a[105];
set<int> se;
void dfs(int x,int loc,vector<int> vec)
{
	se.insert(x);
	for(int i = 0 ; i<t;i++)
	{
		bool flag = false ;
		for(int j = 0;j<vec.size();j++)
		{
			if(vec[i]==loc)
				flag=true;
		}
		if(i!=loc&&!flag)
		{
			if((x+a[i])>0)
				se.insert(x+a[i]);
			vector<int> temp1;
			for(int m = 0;m<vec.size();m++)
				temp1.push_back(vec[m]);
			temp1.push_back(i);
			dfs(x+a[i],loc,temp1);
			if((x-a[i])>0)
				se.insert(x-a[i]);
			vector<int> temp2;
			for(int m = 0;m<vec.size();m++)
				temp2.push_back(vec[m]);
			temp2.push_back(i);
			dfs(x-a[i],loc,temp2);
		}
	}
}
int main()
{
	FastIO;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i < t; i++)
	{
		vector<int> vec;
		vec.push_back(i);
		int x = a[i];
		dfs(x,i,vec);
	}
	cout<<se.size()<<endl;
	return 0;
}
