#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
char a[1010];
char ans[100010];
char str[10][2], s[10];
int main()
{
    int n, c = 0;
    while (std::cin >> n && n)
    {
        int i, t = pow(2.0, n);
        for (i = 0; i < n; i++)
            scanf("%s", str[i]);
        scanf("%s", a + t);
        int m, k = 0;
        scanf("%d", &m);
        for (i = 0; i < m; i++)
        {
            int tmp = 1;
            scanf("%s", s);
            for (int j = 0; j < n; j++)
            {
                if (s[str[j][1] - '0' - 1] == '0')
                    tmp *= 2;
                else
                    tmp = tmp * 2 + 1;
            }
            ans[k++] = a[tmp];
        }
        ans[k] = '\0';
        printf("S-Tree #%d:\n", ++c);
        printf("%s\n\n", ans);
    }
}