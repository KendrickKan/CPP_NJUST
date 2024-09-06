#include <stdio.h>

int add(int a, int b);
int jiecheng(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * jiecheng(n - 1);
    }
}
int main()
{
    printf("Hello, World!\n");
    int a = 10;
    printf("a = %d\n", a);
    int b = a + 10;
    printf("b = %d\n", b);
    int c = add(a, b);
    printf("c = %d\n", c);
    int d = jiecheng(5);
    return 0;
}

int add(int a, int b)
{
    int c = a + b;
    return c;
}