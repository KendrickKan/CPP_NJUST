#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
const int MAXN=100005;
int a[MAXN];
int b[MAXN];
int main()
{
    FastIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum1+=a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            sum2+=b[i];
        }
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(b[i]>a[i])
                {flag=true;
                break;}
        }
        if(flag) cout<<-1<<endl;
        else
            cout<<sum1-sum2<<endl;
    }
    return 0;
}
