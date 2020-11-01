#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct klocation
{
	int kx,ky;
	int bianhao;
	double klength;
};
bool kcmp(klocation a,klocation b)
{
	if(a.klength!=b.klength)
		return a.klength<b.klength;
	else
	 	return a.bianhao<b.bianhao;
}
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	klocation a[205];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
	{
		cin>>a[i].kx>>a[i].ky;
		a[i].bianhao=i+1;
		a[i].klength=(a[i].kx-x)*(a[i].kx-x)+(a[i].ky-y)*(a[i].ky-y);
	}
	sort(a,a+n,kcmp);
	cout<<a[0].bianhao<<endl<<a[1].bianhao<<endl<<a[2].bianhao;
	return 0;
}