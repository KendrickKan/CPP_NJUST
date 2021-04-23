#include<bits/stdc++.h>
using namespace std;
//#define unsigned long long ll
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int main()
{
	FastIO;
	unsigned long long x = 2;
	for(int i = 0;i < 38;i++)
	{
		unsigned long long y = x*2;
		x+=y;
	}
	cout<<x;
	//2701703435345984178
	return 0;
}
