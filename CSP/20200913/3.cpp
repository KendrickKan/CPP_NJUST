#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct kmachine
{
	string func="";
	int k;
	string funcsource[5]={"","","","",""};
	bool havedone=false;
	int intfuncsource[5]={-1,-1,-1,-1,-1};
};
int changeinoutnumtonum(string a)
{
	int n=0;
	for(int i=1;i<a.length();i++)
		n=(a[i]-'0')+n*10;
	return n;
}
bool ifhavedone(int a[],int needout[])
{
	for(int i=1;i<needout[0];i++)
		if(a[needout[i]-1]==-1)
			return false;
	return true;
}
int outputonemachine(kmachine a)
{
	if(a.func=="NOT")
		return !a.intfuncsource[0];
	else if(a.func=="AND")
	{
		int x=a.intfuncsource[0];
		for(int i=1;i<a.k;i++)
		{
			x=x&a.intfuncsource[i];
		}
		return x;
	}
	else if(a.func=="OR")
	{
		int x=a.intfuncsource[0];
		for(int i=1;i<a.k;i++)
		{
			x=x|a.intfuncsource[i];
		}
		return x;
	}
	else if(a.func=="XOR")
	{
		int x=a.intfuncsource[0];
		for(int i=1;i<a.k;i++)
		{
			x=x^a.intfuncsource[i];
		}
		return x;
	}
	else if(a.func=="NAND")
	{
		int x=a.intfuncsource[0];
		for(int i=1;i<a.k;i++)
		{
			x=x&a.intfuncsource[i];
		}
		return !x;
	}
	else if(a.func=="NOR")
	{
		int x=a.intfuncsource[0];
		for(int i=1;i<a.k;i++)
		{
			x=x|a.intfuncsource[i];
		}
		return !x;
	}
}
int main()
{
	int Q;
	cin>>Q;
	while(Q--)
	{
		int M,N;
		cin>>M>>N;
		kmachine a[505];
		for(int i=0;i<N;i++)
		{
			string tempfunc;
			cin>>tempfunc;
			a[i].func=tempfunc;
			cin>>a[i].k;
			for(int j=0;j<a[i].k;j++)
			{
				string tempfuncsource;
				cin>>tempfuncsource;
				a[i].funcsource[j]=tempfuncsource;
			}
		}
		int S;
		int needin[505][205];
		memset(needin,0,sizeof(needin));
		cin>>S;
		for(int i=0;i<S;i++)
			for(int j=0;j<M;j++)
				cin>>needin[i][j];
		int needout[505][505];
		memset(needout,0,sizeof(needout));
		for(int i=0;i<S;i++)
		{
			cin>>needout[i][0];
			for(int j=1;j<=needout[i][0];j++)
				cin>>needout[i][j];
		}
		int output[505];
		for(int i=0;i<S;i++)
		{
			memset(output,-1,sizeof(output));
			for(int j=0;j<N;j++)
			{
				a[j].havedone=false;
				a[j].intfuncsource[0]=a[j].intfuncsource[1]=a[j].intfuncsource[2]=a[j].intfuncsource[3]=a[j].intfuncsource[4]=-1;
			}
			while(ifhavedone(output,needout[i])==false)
			{
				for(int j=0;j<N;j++)
				{
					if(a[j].havedone==true)
						continue;
					else
					{
						for(int p=0;p<a[j].k;p++)
						{
							if(a[j].funcsource[p][0]=='I')
							{
								a[j].intfuncsource[p]=needin[i][changeinoutnumtonum(a[j].funcsource[p])-1];
							}
							else
							{
								if(output[changeinoutnumtonum(a[j].funcsource[p])-1]!=-1)
									a[j].intfuncsource[p]=output[changeinoutnumtonum(a[j].funcsource[p])-1];
								else
									goto stop;
							}
						}
						a[j].havedone=true;
						output[j]=outputonemachine(a[j]);
						stop:;
					}
				}
			}
			for(int j=1;j<needout[i][0];j++)
			{
				cout<<output[needout[i][j]-1]<<' ';
			}
			cout<<output[needout[i][needout[i][0]]-1];
			if(Q!=0)
				cout<<endl;
			else
				if(i!=S-1)
					cout<<endl;
		}
	}
	return 0;
}
