#include <bits/stdc++.h>
using namespace std;
int candymap[1005][1005];
int sum[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--)
    {
        memset(candymap,0,sizeof(candymap));
        memset(sum,0,sizeof(sum));
        int n,m;
        int max;
        int temp;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>candymap[i][j];
        max=candymap[n][m];
        for(int i=n;i>0;i--)
        {
            for(int j=m;j>0;j--)
            {
                candymap[i][j]+=candymap[i][j+1];
            }
        }
        for(int i=n;i>0;i--)
        {
            for(int j=m;j>0;j--)
            {
                sum[i][j]=candymap[i][j]+candymap[i+1][j];
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(sum[i][j]>max)
                    max=sum[i][j];
            }
        cout<<max<<endl;
    }
    return 0;
}
