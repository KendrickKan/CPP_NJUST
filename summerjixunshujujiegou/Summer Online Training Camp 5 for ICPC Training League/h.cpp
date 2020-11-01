#include <stdio.h>
int lowbit(int x)
{
    return x & (-x);
}
int main()
{
    int T, x;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &x);
        printf("%d %d\n", x - lowbit(x) + 1, x + lowbit(x) - 1);
    }
    return 0;
}