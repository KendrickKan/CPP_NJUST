#include <bits/stdc++.h>
using namespace std;
struct peotime
{
    int huihe, didian;
};

struct people
{
    bool ganran = false;
    int x;
    peotime tm[105];
};

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        people a[20005];
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].x;
            for (int j = 0; j < a[i].x; j++)
            {
                cin >> a[i].tm[j].huihe;
                cin >> a[i].tm[j].didian;
            }
        }
        a[0].ganran = true;
        for (int i = 1; i <= 100; i++)
        {
            int num = 0;
            bool ifhave = false;
            int ren[20005];
            memset(ren, 0, sizeof(ren));
            for (int j = 0; j < n; j++)
            {
                for (int k; k < a[j].x; k++)
                {
                    if (a[j].tm[k].huihe == i)
                    {
                        ren[num]=j;
                        num++;
                    }
                }
            }
        }
    }

    return 0;
}
