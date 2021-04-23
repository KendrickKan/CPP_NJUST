#include<bits/stdc++.h>
using namespace std;
#define long long ll
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int t;
int n;
bool cmp(int a,int b)
{
    return a<b;
}
bool cmp1(int a,int b)
{
    return a>b;
}
int a[2];
int main()
{
	FastIO;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> vec;
        for(int i = 0;i<n;i++)
        {
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }
        a[0]=0;
        a[1]=0;
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<n;i++)
        {
                if(a[i%2]^vec[vec.size()-1]>a[i%2])
                {
                    a[i%2]=a[i%2]^vec[vec.size()-1];
                    vec.pop_back();
                }
                else{
                    a[i%2+1]=a[i%2+1]^vec[vec.size()-1];
                }
        }
        if(a[0]>a[1])
            cout<<1<<endl;
        else if(a[0]==a[1])
            cout<<0<<endl;
        else cout<<-1<<endl;
        //992438 1006399 781139 985280 4729 872779 563580
    }
	return 0;
}
