/*
 * @Author: KendrickKan 
 * @Date: 2020-09-27 09:05:30 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-09-27 09:22:20
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct chicken
{
    int num;
    int loc;
};
bool cmp(chicken a, chicken b)
{
    if (a.num != b.num)
        return a.num > b.num;
    else
    {
        return a.loc < b.loc;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    chicken vec[100004];
    for (int i = 0; i < 100004; i++)
    {
        vec[i].loc = i;
        vec[i].num = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec[x].num++;
    }
    //sort(vec, vec + n, cmp);
    int cnt = 0;
    for (int i = 0; i < 100004; i++)
    {
        if (vec[i].num >= k)
        {
            cnt += vec[i].num - 1;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}