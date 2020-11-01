#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct kpeople
{
	int maxlianxudouliu;
	int ifjingguo;	
	int ifdouliu;
};
int main()
{
	int n,k,t,xl,yd,xr,yu;
	cin>>n>>k>>t>>xl>>yd>>xr>>yu;
	kpeople a[25];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
	{
		int maxl=0;
		int temp=0;
		for(int j=0;j<t;j++)
		{
			int x,y;
			cin>>x>>y;
			if(x>=xl&&x<=xr&&y<=yu&&y>=yd)
			{
				temp++;
				if(a[i].ifjingguo==0)
					a[i].ifjingguo=1;
				if(temp>maxl)
					maxl=temp;
			}
			else
				temp=0;
		}
		if(maxl>=k)
			a[i].ifdouliu=1;
	}
	int jingguo=0,douliu=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].ifdouliu==1)
			douliu++;
		if(a[i].ifjingguo==1)
			jingguo++;
	}
	cout<<jingguo<<endl<<douliu;
	return 0;
}