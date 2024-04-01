#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 505

struct station
{
    float p;
    float d;
} st[maxn];
bool cmp(station a, station b)
{
    return a.d < b.d;
}

int main()
{
    float cap, dis, dav;
    int n;
    scanf("%f %f %f %d", &cap, &dis, &dav, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &st[i].p, &st[i].d);
    }
    sort(st, st + n, cmp);
    st[n].d = dis;
    st[n].p = 0;
    // 初始状态下没油，如果第一个加油站不在起点，直接G
    if (st[0].d != 0)
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    // 从满油状态下能到达的加油站里挑
    // 可达范围有更低价格的，则加正好的油去更便宜的加油站
    // 没有更低价格的，则在现在这个站加满，然后去可达范围内最便宜的
    // 可达范围没有加油站，就G（比较一下能不能到达终点）
    int scope = dav * cap; // 加满距离
    int curSt = 0;
    float maxlong = 0;
    float ans = 0;
    float curOil = 0;
    while (curSt < n)
    {
        int k = -1;
        float minp = 1e9;
        for (int i = curSt + 1; i <= n && st[curSt].d + scope >= st[i].d; i++)
        {
            if (st[i].p < minp)
            {
                minp = st[i].p;
                k = i;
            }
            if (minp < st[curSt].p)
                break;
        }
        if (k == -1)
        { // 范围内无
            maxlong = st[curSt].d + scope;
            printf("The maximum travel distance = %.2f\n", maxlong);
            break;
        }
        if (st[curSt].p < minp)
        { // 没更低的
            ans += (cap - curOil) * st[curSt].p;
            curOil = cap;
            curOil -= (st[k].d - st[curSt].d) / dav;
        }
        else
        { // 有更便宜的
            // 考虑邮箱本身的油量
            ans += ((st[k].d - st[curSt].d) / dav - curOil) * st[curSt].p;
            curOil = (st[k].d - st[curSt].d) / dav;
            curOil = 0;
        }
        curSt = k;
        if (curSt == n)
        {
            printf("%.2f\n", ans);
            return 0;
        }
    }
    return 0;
}