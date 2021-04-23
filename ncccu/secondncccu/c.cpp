#include <iostream> 
#include <cstdio>  
#include <algorithm> 
#include <cmath>    
#include <string>   
#include <cstring>  
#include <vector>  
#include <queue>    
#include <stack>   
#include <set>      
#include <map>      
using namespace std;
int main()
{
    int h,m,s;
    scanf("%d:%d:%d",&h,&m,&s);
    int n;
    scanf("%d",&n);
    if(s+n>=60)
    {
        m+=1;
 
        if(m>=60)
        {
            h+=1;
 
        }
    }
    s=(s+n)%60;
    m%=60;
    h%=24;
    printf("%02d:%02d:%02d",h,m,s);
    return 0;
}