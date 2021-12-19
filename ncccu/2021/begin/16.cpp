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
    int n = 0;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        if (str[1] == '*' && str[3] == '*')
        {
            cout << (str[0] - '0') * (str[2] - '0') * (str[4] - '0');
        }
        else if (str[1] == '*' && str[3] == '+')
        {
            cout << (str[0] - '0') * (str[2] - '0') + (str[4] - '0');
        }
        else if (str[1] == '*' && str[3] == '-')
        {
            cout << (str[0] - '0') * (str[2] - '0') - (str[4] - '0');
        }
        else if (str[1] == '+' && str[3] == '-')
        {
            cout << (str[0] - '0') + (str[2] - '0') - (str[4] - '0');
        }
        else if (str[1] == '+' && str[3] == '+')
        {
            cout << (str[0] - '0') + (str[2] - '0') + (str[4] - '0');
        }
        else if (str[1] == '+' && str[3] == '*')
        {
            cout << (str[0] - '0') + (str[2] - '0') * (str[4] - '0');
        }
        else if (str[1] == '-' && str[3] == '-')
        {
            cout << (str[0] - '0') - (str[2] - '0') - (str[4] - '0');
        }
        else if (str[1] == '-' && str[3] == '+')
        {
            cout << (str[0] - '0') - (str[2] - '0') + (str[4] - '0');
        }
        else
        {
            cout << (str[0] - '0') - (str[2] - '0') * (str[4] - '0');
        }
        cout << endl;
    }
    return 0;
}