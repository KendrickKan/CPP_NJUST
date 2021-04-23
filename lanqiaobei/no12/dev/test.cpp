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
    //unsigned long long temp = 2;
    cout<<(temp-1)*(temp-1)*temp<<endl;
    unsigned long long ans =0;
    for(unsigned long long i =1;i<temp;i++)
    {
        if(n%i==0)
        {
        	unsigned long long temooo = 0;
        	unsigned long long kkk = n/i;
            for(unsigned long long j =1;j<sqrt(kkk);j++)
            {
                if(kkk%j==0)
                temooo++;
                    //temooo++;
            }
            if((unsigned long long)sqrt(kkk)*(unsigned long long)sqrt(kkk)==kkk)
            	temooo++;
            ans+=temooo;
        }
    }
    cout<<ans*3<<endl;
    //cout<<126432*126432*126432<<endl;
	return 0;
}

