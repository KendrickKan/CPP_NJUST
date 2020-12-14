#include <bits/stdc++.h>
//<algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
struct stu
{
    int id;
    int totalscore;
    int kmath;
};
bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
bool cmp1(stu a, stu b)
{
    if (a.totalscore != b.totalscore)
    {
        return a.totalscore > b.totalscore;
    }
    else
    {
        if (a.kmath != b.kmath)
        {
            return a.kmath > b.kmath;
        }
        else
            return a.id < b.id;
    }
}
int main()
{
    // int a[5] = {2, 4, 2, 6, 7};
    // sort(a, a + 5, cmp);
    stu st[4];
    st[0].id = 1;
    st[0].totalscore = 100;
    st[0].kmath = 10;
    st[1].id = 3;
    st[1].totalscore = 100;
    st[1].kmath = 18;
    st[2].id = 2;
    st[2].totalscore = 10;
    st[2].kmath = 1;
    st[3].id = 4;
    st[3].totalscore = 100;
    st[3].kmath = 10;
    sort(st, st + 4, cmp1);
    return 0;
}