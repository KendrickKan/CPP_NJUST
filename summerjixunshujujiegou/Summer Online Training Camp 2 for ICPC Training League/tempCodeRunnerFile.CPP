#include <stdio.h>
int father[30011], deep[30011], h[30011]; //数组H[i]表示i下有多少个方块 ，deep[i]表示i所在栈堆的高度
int find(int x)
{
    if (x != father[x])
    {
        int t = father[x];
        father[x] = find(father[x]);
        h[x] += h[t];
    }
    return father[x];
}
void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        father[x] = y;
        h[x] = deep[y];
        deep[y] += deep[x];
        deep[x] = 0;
    }
}
int main()
{
    int n, a, b, p;
    char op[2];
    scanf("%d", &n);
    for (int i = 1; i < 30001; i++)
    {
        father[i] = i;
        deep[i] = 1;
        h[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", op);
        if (op[0] == 'M')
        {
            scanf("%d%d", &a, &b);
            join(a, b);
        }
        else
        {
            scanf("%d", &p);
            int k = find(p);
            printf("%d\n", h[p]);
        }
    }
    return 0;
}