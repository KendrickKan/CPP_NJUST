#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		
		string str;
		cin>>str;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='R')
				cout<<"P";
			else if(str[i]=='P')
				cout<<"S";
			else
				cout<<"R";
		}
		cout<<endl;
	}
	return 0;
}
