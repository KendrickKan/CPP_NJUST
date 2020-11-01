#include <cstdio>
#include <vector>
using namespace std;
int P[1000][9];
int tmp[8];
int n = 0;
bool col[8] = {0}, left[15] = {0}, right[15] = {0};
void func(int r)
{
    if (r == 8)
    {
        for (int i = 0; i < 8; ++i)
            P[n][i] = tmp[i];
        ++n;
        return;
    }
    for (int c = 0; c < 8; ++c)
    {
        int ld = (c - r) + 7;
        int rd = c + r;
        if (!col[c] && !left[ld] && !right[rd])
        {
            col[c] = 1, left[ld] = 1, right[rd] = 1;
            tmp[r] = c;
            func(r + 1);
            col[c] = 0, left[ld] = 0, right[rd] = 0;
        }
    }
}
int main()
{
    func(0);

    int t, x, y;
    while (~scanf("%d", &t))
        while (t--)
        {
            scanf("%d%d", &x, &y);

            printf("SOLN       COLUMN\n");
            printf(" #      1 2 3 4 5 6 7 8\n\n");
            int count = 1;
            for (int i = 0; i < n; ++i)
                if (P[i][y - 1] == x - 1)
                {
                    printf("%2d     ", count++);
                    for (int j = 0; j < 8; ++j)
                    {
                        int temp = P[i][j] + 1;
                        printf(" %d", temp);
                    }
                    printf("\n");
                }
            if (t)
                printf("\n");
        }
    return 0;
}