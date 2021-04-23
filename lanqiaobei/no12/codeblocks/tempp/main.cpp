#include<bits/stdc++.h>
using namespace std;
#define long long ll
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int t;
int a[105];
set<int> se;
set<int> totalse;
vector<int> vec;
int main()
{
	FastIO;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		cin>>a[i];
	}
	vec.push_back(0);
	totalse.insert(0);
	vec.push_back(a[0]);
	totalse.insert(a[0]);
	se.insert(a[0]);
	vec.push_back(0-a[0]);
	totalse.insert(0-a[0]);
	int ans = se.size();
	for(int i = 1 ; i<t;i++)
    {
        int ktemp = vec.size();
        for(int j=0;j<ktemp;j++)
        {
            int temp = a[i]-vec[j];
            int tempnum = totalse.size();
            totalse.insert(temp);
            if(tempnum!=totalse.size())
            {
                vec.push_back(temp);
                if(temp>0)
                    se.insert(temp);
                    ans=se.size();
            }
            temp = a[i]+vec[j];
            tempnum = totalse.size();
            totalse.insert(temp);
            if(tempnum!=totalse.size())
            {
                vec.push_back(temp);
                if(temp>0)
                    se.insert(temp);
                    ans=se.size();
            }
            temp = vec[j]-a[i];
            tempnum = totalse.size();
            totalse.insert(temp);
            if(tempnum!=totalse.size())
            {
                vec.push_back(temp);
                if(temp>0)
                    se.insert(temp);
                    ans=se.size();
            }
        }
    }
	cout<<se.size()<<endl;
	return 0;
}
