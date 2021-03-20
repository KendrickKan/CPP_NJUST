/*
 * @Author: KendrickKan 
 * @Date: 2021-03-20 21:30:04 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-03-20 21:58:03
 * @about：Union_Find
 */
#include <bits/stdc++.h>
using namespace std;
const int maxnum = 1000;
int pre[maxnum];
int Rank[maxnum];

void Init(int n)
{
    for (int i = 0; i < n; i++)
    {
        pre[i] = i;
        Rank[i] = 1;
    }
}
int Find(int x)
{
    if (pre[x] == x)
        return x;
    return pre[x] = Find(pre[x]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return false;
    if (Rank[x] > Rank[y])
        pre[y] = x;
    else
    {
        if (Rank[x] == Rank[y])
            Rank[y]++;
        pre[x] = y;
    }
    return true;
}

int main()
{
    return 0;
}