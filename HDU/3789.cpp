#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct country
{
    int location;
    int gold, medal, population;
    //
    //    double pergold, permedal;
    int one, two, three, four;
    int ifjudge = 0;
};
bool cmp(country a, country b)
{
    return a.location < b.location;
}
bool cmp1(country a, country b)
{
    return a.gold > b.gold;
}
bool cmp2(country a, country b)
{
    return a.medal > b.medal;
}
bool cmp3(country a, country b)
{
    return (a.gold / a.population) > (b.gold / b.population);
}
bool cmp4(country a, country b)
{
    return (a.medal / a.population) > (b.medal / b.population);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    while (cin >> n >> m)
    {
        country a[10005];
        int b[10005];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i++)
        {
            a[i].location = i;
            cin >> a[i].gold >> a[i].medal >> a[i].population;
            //a[i].pergold = a[i].gold / a[i].population;
            //a[i].permedal = a[i].medal / a[i].population;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            a[b[i]].ifjudge = 1;
        }
        int nowmingci = 1, mingci = 1;
        int before, la;
        sort(a, a + n, cmp1);
        for (int i = 0; i < n; i++)
            if (a[i].ifjudge == 1)
            {
                before = a[i].gold;
                la = i;
                a[i].one = 1;
                break;
            }
        for (int i = la + 1; i < n; i++)
        {
            if (a[i].ifjudge == 1)
            {
                mingci++;
                if (a[i].gold == before)
                    a[i].one = nowmingci;
                else
                {
                    before = a[i].gold;
                    a[i].one = mingci;
                    nowmingci = mingci;
                }
            }
        }
        nowmingci = mingci = 1;
        sort(a, a + n, cmp2);
        for (int i = 0; i < n; i++)
            if (a[i].ifjudge == 1)
            {
                before = a[i].medal;
                la = i;
                a[i].two = 1;
                break;
            }
        for (int i = la + 1; i < n; i++)
        {
            if (a[i].ifjudge == 1)
            {
                mingci++;
                if (a[i].medal == before)
                    a[i].two = nowmingci;
                else
                {
                    before = a[i].medal;
                    a[i].two = mingci;
                    nowmingci = mingci;
                }
            }
        }
        double befored;
        nowmingci = mingci = 1;
        sort(a, a + n, cmp3);
        for (int i = 0; i < n; i++)
            if (a[i].ifjudge == 1)
            {
                befored = a[i].gold / a[i].population;
                la = i;
                a[i].three = 1;
                break;
            }
        for (int i = la + 1; i < n; i++)
        {
            if (a[i].ifjudge == 1)
            {
                mingci++;
                if (a[i].gold / a[i].population == befored)
                    a[i].three = nowmingci;
                else
                {
                    befored = a[i].gold / a[i].population;
                    a[i].three = mingci;
                    nowmingci = mingci;
                }
            }
        }
        nowmingci = mingci = 1;
        sort(a, a + n, cmp4);
        for (int i = 0; i < n; i++)
            if (a[i].ifjudge == 1)
            {
                befored = a[i].medal / a[i].population;
                la = i;
                a[i].four = 1;
                break;
            }
        for (int i = la + 1; i < n; i++)
        {
            if (a[i].ifjudge == 1)
            {
                mingci++;
                if (a[i].medal / a[i].population == befored)
                    a[i].four = nowmingci;
                else
                {
                    befored = a[i].medal / a[i].population;
                    a[i].four = mingci;
                    nowmingci = mingci;
                }
            }
        }
        sort(a, a + n, cmp);
        for (int i = 0; i < m; i++)
        {
            int x = b[i];
            int minl = a[x].one;
            int method = 1;
            if (a[x].two < minl)
            {
                minl = a[x].two;
                method = 2;
            }
            if (a[x].three < minl)
            {
                minl = a[x].three;
                method = 3;
            }
            if (a[x].four < minl)
            {
                minl = a[x].four;
                method = 4;
            }
            cout << minl << ':' << method << endl;
        }
        cout << endl;
    }
    return 0;
}