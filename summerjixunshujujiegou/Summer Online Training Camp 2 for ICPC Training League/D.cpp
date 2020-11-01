#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
char str[100010];
int q;
#define p 233
map<ull, int> ma;
ull Hash[100010], a[100010];
int n, len;
struct node
{
    int ha, id;
} qwe[100010];
bool cmp(node a, node b)
{
    if (a.ha == b.ha)
        return a.id < b.id; //id大的放在后面有助于找到最后面的起始位置

    else
        return a.ha < b.ha;
}
void init(int len) //初始化hash
{
    Hash[0] = 0;
    for (int i = 1; i <= len; i++)
    {
        Hash[i] = Hash[i - 1] * p + str[i];
    }
    a[0] = 1;
    for (int i = 1; i < 100010; i++)
    {
        a[i] = a[i - 1] * p;
    }
}
int judge(int l)
{

    int ans = -1, i, j;
    qwe[0].ha = Hash[0];
    qwe[0].id = 0;
    for (i = 1; i <= len - l + 1; i++)
    {
        qwe[i].ha = Hash[i + l - 1] - Hash[i - 1] * a[l];
        qwe[i].id = i;
    }
    sort(qwe, qwe + len - l + 2, cmp);
    for (i = 0; i <= len - l + 1; i++)
    {
        int v = 0;
        for (j = i; qwe[i].ha == qwe[j].ha && j <= len - l + 1; j++)
        {
            v++;
            if (v >= n)
            {
                ans = max(ans, qwe[j].id - 1);
            }
        }
        i = j - 1;
    }
    return ans;
}
int main()
{
    while (scanf("%d", &n) && n)
    {

        scanf("%s", str + 1);
        len = strlen(str + 1);
        init(len);
        int l = 0, r = len + 1;
        while (l <= r) //二分
        {
            int mid = (l + r) / 2;
            if (judge(mid) != -1)
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        if (judge(1) == -1)
            puts("none"); //注意这个判断条件
        else
            printf("%d %d\n", r, judge(r));
    }
    return 0;
}