#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int t,n;
	int flag1=0,flag2=0,a,b,x; 
	cin>>t;
	while(t--)
	{
		cin>>n;
		int p[10000];
		for(int i=0;i<n;i++)
			cin>>p[i];
		for(x=1;x<n-1;x++)
		{
			for(a=0;a<x;a++)
			{
				if(p[a]<p[x])
				{
					flag1=1;
					break;
				}
			}
			for(b=n-1;b>x;b--)
			{
				if(p[b]<p[x])
				{
					flag2=1;
					break;
				}
			}	
			if(flag1&&flag2)
				break;
			flag1=flag2=0;
		}
		if(flag1&&flag2)
		{
			cout<<"YES"<<endl;
			
			cout<<a+1<<" "<<x+1<<" "<<b+1<<endl;
			
			flag1=flag2=0;
		}
		else
			cout<<"NO"<<endl;	
	}
	return 0;
}
