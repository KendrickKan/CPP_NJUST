#include <bits/stdc++.h>
using namespace std;
int changestringtotime(string str)
{
    int time;
    time = ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + ((str[3] - '0') * 10 + (str[4] - '0'));
    return time;
}
bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    int twotable[105], fourtable[105], sixtable[105];
    int a, b, c;
    while (cin >> a >> b >> c && (a || b || c))
    {
        memset(twotable, 0, sizeof(twotable));
        memset(fourtable, 0, sizeof(fourtable));
        memset(sixtable, 0, sizeof(sixtable));
        int ans = 0, num, time, *p;
        string peopletime;
        while (cin >> peopletime && peopletime != "#")
        {
            sort(twotable, twotable + a, cmp);
            sort(fourtable, fourtable + b, cmp);
            sort(sixtable, sixtable + c, cmp);
            time = changestringtotime(peopletime);
            cin >> num;
            if (num == 1 || num == 2)
                p = twotable;
            else if (num == 3 || num == 4)
                p = fourtable;
            else
                p = sixtable;
            if (*p <= time + 30)
            {
                if (*p <= time)
                    *p = time + 30;
                else
                    *p += 30;
                ans += num;
            }
        }
        cout << ans << endl;
    }
    return 0;
}