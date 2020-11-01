#include<iostream>
using namespace std;
int main()
{
    int n,sum,flag,num;
    flag=sum=0;
    while (cin>>n&&n)
    {
        flag++;
        sum+=n;
        if(sum>=50)
        {
            num=sum/50;
            sum-=(num*50);
            if(num==1)
                {
                    cout<<"Input #"<<flag<<": Sweet!"<<endl;
                }
                else
                {
                    cout<<"Input #"<<flag<<": Totally Sweet!"<<endl;
                }      
        }
    }
    
    return 0;
}