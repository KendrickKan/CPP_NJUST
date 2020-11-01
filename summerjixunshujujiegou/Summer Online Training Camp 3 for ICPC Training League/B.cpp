#include <iostream>
#include <cstring>
#define max 100002
using namespace std;
struct node1
{
    int next, tail;
} edge[max];
struct node2
{
    int r, l;
} apple[max];
int s[max], cnt, c[max], a[max];
void DFS(int u)
{
    int i;
    apple[u].l = cnt;
    for (i = s[u]; i != -1; i = edge[i].next)
        DFS(edge[i].tail);
    apple[u].r = cnt++;
}
inline int lowbit(int x)
{
    return x & (-x);
}
void change(int x)
{
    int i;
    if (a[x])
        for (i = x; i < cnt; i += lowbit(i))
            c[i]++;
    else
        for (i = x; i < cnt; i += lowbit(i))
            c[i]--;
}
int sum(int x)
{
    int i, res = 0;
    for (i = x; i > 0; i -= lowbit(i))
        res += c[i];
    return res;
}
int main()
{
    int i, n, m, t1, t2, t;
    char str[3];
    scanf("%d", &n);
    memset(s, -1, sizeof(s[0]) * (n + 1));
    memset(c, 0, sizeof(c[0]) * (n + 1));
    memset(apple, 0, sizeof(apple[0]) * (n + 1));
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &t1, &t2);
        edge[i].tail = t2;
        edge[i].next = s[t1];
        s[t1] = i;
    }
    cnt = 1;
    DFS(1);
    scanf("%d", &m);
    for (i = 1; i <= n; i++)
    {
        a[i] = 1;
        change(i);
    }
    while (m--)
    {
        scanf("%s%d", &str, &t);
        if (str[0] == 'Q')
            printf("%d\n", sum(apple[t].r) - sum(apple[t].l - 1));
        else
        {
            a[apple[t].r] = (a[apple[t].r] + 1) % 2;
            change(apple[t].r);
        }
    }
    return 0;
}