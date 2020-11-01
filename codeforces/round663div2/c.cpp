#include <bits/stdc++.h>
using namespace std;
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
ll MOD =1e9+7;
int main()
{
    IOS;
    ll n;
    cin>>n;
    ll x=1, y=1;
    for (int i=2;i<=n;i++)
    {
        x=x*i%MOD;
        y=y*2%MOD;
    }
    cout<<(x-y+MOD)%MOD<<endl;
    return 0;
}