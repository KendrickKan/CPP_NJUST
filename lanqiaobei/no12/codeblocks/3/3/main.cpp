#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int main()
{
	FastIO;
	unsigned long long n = 2021041820210418;
	//unsigned long long n = 4;
    for(unsigned long long i = 1;i<n;i++)
    {
        if(i*i*i>=n){
        cout<<i<<endl;
        break;}

    }
    unsigned long long temp = 126433;
    cout<<(temp-1)*(temp-1)*temp<<endl;
    unsigned long long ans =0;
    for(unsigned long long i =1;i<=n;i++)
    {
        if(n%i==0)
        {
            for(unsigned long long j =1;j<=n/i;j++)
            {
                if(n/i%j==0)
                    ans++;
            }
        }
    }
    cout<<ans<<endl;
    //cout<<126432*126432*126432<<endl;
	return 0;
}
