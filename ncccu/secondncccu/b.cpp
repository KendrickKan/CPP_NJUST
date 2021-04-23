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
    int n;
    cin >> n;
    int a[105];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = ans * __gcd(a[i], a[j]);
            ans %= 1000000007;
        }
    }
    cout << ans;
    return 0;
}