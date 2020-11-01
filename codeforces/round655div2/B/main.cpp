#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll GreatestCommonDivisor(ll a, ll b) {
    ll t;
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
ll LeastCommonMultiple(ll a, ll b) {
    ll t = a * b / GreatestCommonDivisor(a, b);
    return t;
}
int main()
{
	int t;
	ll n,p;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll a=1,b=n-1;
		p=LeastCommonMultiple(1,n-1);
		if(n<1000){
		for(ll i=2;i<(n/2+1);i++)
		{
			if(LeastCommonMultiple(i,n-i)<p){
				p=LeastCommonMultiple(i,n-i);
				a=i;
				b=n-i;
				if(LeastCommonMultiple(i,n-i)<(n/2+1)) 
					goto stop;
			}
		}
		stop:
		cout<<a<<" "<<b<<endl; 
		}
		else
		{
		for(ll i=(n/4-1);i<(n/2+1);i++)
		{
			if(LeastCommonMultiple(i,n-i)<p){
				p=LeastCommonMultiple(i,n-i);
				a=i;
				b=n-i;
				if(LeastCommonMultiple(i,n-i)<(n/2+1)) 
					goto stop1;
			}
		}
		stop1:
		cout<<a<<" "<<b<<endl; 
		}
	}
	return 0;
} 
