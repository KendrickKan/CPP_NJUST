#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <stack>
using namespace std;
int c[100009], f[100009];
int find_father(int a)
{
    if (c[a] == a)
        return a;
    c[a] = find_father(c[a]);
    return c[a];
}
void bingchaji(int a, int b)
{
    a = find_father(a);
    b = find_father(b);
    if (f[a] != a)
    {
        c[f[a]] = b;
    }
    f[a] = b;
    if (f[b] != b)
    {
        c[f[b]] = a;
    }
    f[b] = a;
}
int main()
{
    int t, n, m, i, a, b;
    char d;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        getchar();
        for (i = 1; i <= n; i++)
        {
            c[i] = i;
            f[i] = i;
        }
        for (i = 1; i <= m; i++)
        {
            scanf("%c %d %d", &d, &a, &b);
            getchar();
            if (d == 'D')
            {
                bingchaji(a, b);
            }
            else
            {
                a = find_father(a);
                b = find_father(b);
                if (a == b)
                    printf("In the same gang.\n");
                else if (f[a] == b || f[b] == a)
                    printf("In different gangs.\n");
                else
                    printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}