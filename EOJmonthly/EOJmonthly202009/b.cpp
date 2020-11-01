/*
 * @Author: KendrickKan 
 * @Date: 2020-09-26 19:53:20 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-09-26 20:55:00
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct build
{
    int loc;
    int num;
    int havedone;
    vector<int> link;
};
bool cmp(build a, build b)
{
    return a.num < b.num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> vec;
    vector<build> building;
    vector<int> building2;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
    {
        building2.push_back(0);
    }
    for (int i = 0; i <= n; i++)
    {
        build x;
        x.num = 0;
        x.loc = i;
        x.havedone = 0;
        building.push_back(x);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        building[x].link.push_back(y);
        building[y].link.push_back(x);
        building[x].num++;
        building[y].num++;
        vec.push_back(make_pair(x, y));
    }
    sort(building.begin(), building.end(), cmp);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        bool flag = 0;
        for (int j = 0; j < building[i].link.size(); j++)
        {
            if (building2[building[i].link[j]] >= k)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cnt++;
            building2[i]++;
        }
    }
    cout << cnt << endl;
    return 0;
}