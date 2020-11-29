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
struct people
{
    int id;
    int xuan, tian, ying;
    int zong;
};
people p[505];
bool cmpxuan(people a, people b)
{
    if (a.xuan != b.xuan)
        return a.xuan > b.xuan;
    else
        return a.id < b.id;
}
bool cmptian(people a, people b)
{
    if (a.tian != b.tian)
        return a.tian > b.tian;
    else
        return a.id < b.id;
}
bool cmpying(people a, people b)
{
    if (a.ying != b.ying)
        return a.ying > b.ying;
    else
        return a.id < b.id;
}
bool cmpz(people a, people b)
{
    if (a.zong != b.zong)
        return a.zong > b.zong;
    else
    {
        if (a.ying != b.ying)
            return a.ying > b.ying;
        else
        {
            if (a.tian != b.tian)
                return a.tian > b.tian;
            else
            {
                if (a.xuan != b.xuan)
                    return a.xuan > b.xuan;
                else
                    return a.id < b.id;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].id;
        cin >> p[i].xuan;
        cin >> p[i].tian;
        cin >> p[i].ying;
        p[i].zong = p[i].xuan + p[i].tian + p[i].ying;
    }
    sort(p, p + n, cmpxuan);
    cout << p[0].id << " " << p[0].xuan << endl;
    sort(p, p + n, cmptian);
    cout << p[0].id << " " << p[0].tian << endl;
    sort(p, p + n, cmpying);
    cout << p[0].id << " " << p[0].ying << endl;
    cout << endl;
    sort(p, p + n, cmpz);
    cout << p[0].id << " " << p[0].zong << endl;
    cout << p[1].id << " " << p[1].zong << endl;
    cout << p[2].id << " " << p[2].zong << endl;
    return 0;
}