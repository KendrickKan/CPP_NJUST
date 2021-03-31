#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
int main()
{
    FastIO;
    int t;
    cin>>t;
    while(t--)
    {
        int p,q;
        cin>>p>>q;
        int putong=10000,qijianxianding=10000,fes=10000;
        qijianxianding=p*90+(100-p)*110;
        fes=q*115;
        if(fes==max(fes,max(putong,qijianxianding))) cout<<"Festival"<<endl;
        else if(qijianxianding==max(fes,max(putong,qijianxianding))) cout<<"Limited"<<endl;
        else cout<<"Permanent"<<endl;
}
    return 0;
}
