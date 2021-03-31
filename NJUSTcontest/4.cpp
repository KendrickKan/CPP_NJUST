#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
int a[205];
int main()
{
    FastIO;
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a[x]++;
        }
        int maxnum=0;
        for(int i=0;i<205;i++)
        {
            maxnum=max(maxnum,a[i]);
        }
        if(maxnum>n/2)
            cout<<-1<<endl;
        else{

        }
    }
    return 0;
}
