#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int a[N][N];
int n, m, t, p, d, c, U, D, L, R;
void init()
{
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = 1;
        }
    }
}
void show()
{
    for (int j = U - 1; j >= D; j--)
    {
        for (int i = L; i < R; i++)
        {
            printf("%d%c", a[i][j], i == R - 1 ? '\n' : ' ');
        }
    }
}
int main()
{
    while (cin >> n >> m >> t >> p && (n || m || t || p))
    {
        init();
        D = 0, L = 0, U = m, R = n;
        //show();
        while (t--)
        {
            cin >> d >> c;
            if (d == 1)
            {
                for (int i = L, k = 1; i < L + c; i++, k++)
                {
                    for (int j = D; j < U; j++)
                    {
                        a[L + 2 * c - k][j] += a[i][j];
                        //a[i][j]=0;
                    }
                }
                c = L + c;
                if (c - L > R - c)
                {
                    R = (c - L) + c;
                }
                L = c;
            }
            else
            {
                for (int i = L; i < R; i++)
                {
                    for (int j = D, k = 1; j < D + c; j++, k++)
                    {
                        a[i][D + 2 * c - k] += a[i][j];
                        //a[i][j]=0;
                    }
                }
                c = D + c;
                if (c - D > U - c)
                {
                    U = (c - D) + c;
                }
                D = c;
            }
            //printf("L:%d R:%d D:%d U:%d\n",L,R,D,U);
            //show();
        }
        int x, y;
        for (int i = 1; i <= p; i++)
        {
            cin >> x >> y;
            printf("%d\n", a[x + L][y + D]);
        }
    }
    return 0;
}