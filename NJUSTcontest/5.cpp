#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
const int MAXN=1005;
int a[MAXN];
int b[MAXN];
bool c[MAXN];
int main()
{
    FastIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        c[n-1]=false;
        for(int i=n-2;i>=0;i--)
        {
            if((c[i+a[i]]==false&&(i+a[i])<n)||(c[i+b[i]]==false&&(i+b[i])<n))
                c[i]=true;
            else c[i]=false;
        }
        if(c[0]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
