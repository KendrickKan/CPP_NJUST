#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct studentpeole
{
    int num;
    char str[8];
    int score;
};
struct totalscore
{
    char shijian[8];
    int xuhao;
};
totalscore fournum[105];
totalscore threenum[105];
totalscore twonum[105];
totalscore onenum[105];
studentpeole people[105];
int changestirngtonum(totalscore x)
{
    int totaltime = 0;
    totaltime = ((x.shijian[0] - '0') * 10 + (x.shijian[1] - '0')) * 3600 + ((x.shijian[3] - '0') * 10 + (x.shijian[4] - '0')) * 60 + ((x.shijian[6] - '0') * 10 + (x.shijian[7] - '0'));
    return totaltime;
}
bool cmp(totalscore a, totalscore b)
{
    return changestirngtonum(a) < changestirngtonum(b);
}
int main()
{
    int n;
    cin >> n;
    while (1)
    {
        memset(people, 0, sizeof(people));
        memset(fournum, 0, sizeof(fournum));
        memset(threenum, 0, sizeof(threenum));
        memset(twonum, 0, sizeof(twonum));
        memset(onenum, 0, sizeof(onenum));
        int fuorsum = 0, threesum = 0, twosum = 0, onesum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> people[i].num;
            for (int j = 0; j < 8; j++)
                cin >> people[i].str[j];
            if (people[i].num == 5)
                people[i].score = 100;
            if (people[i].num == 0)
                people[i].score = 50;
            if (people[i].num == 4)
            {
                for (int j = 0; j < 8; j++)
                    fournum[fuorsum].shijian[j] = people[i].str[j];
                fournum[fuorsum].xuhao = i;
                fuorsum++;
            }
            if (people[i].num == 3)
            {
                for (int j = 0; j < 8; j++)
                    threenum[threesum].shijian[j] = people[i].str[j];
                threenum[threesum].xuhao = i;
                threesum++;
            }
            if (people[i].num == 2)
            {
                for (int j = 0; j < 8; j++)
                    twonum[twosum].shijian[j] = people[i].str[j];
                twonum[twosum].xuhao = i;
                twosum++;
            }
            if (people[i].num == 1)
            {
                for (int j = 0; j < 8; j++)
                    onenum[onesum].shijian[j] = people[i].str[j];
                onenum[onesum].xuhao = i;
                onesum++;
            }
        }
        sort(fournum, fournum + fuorsum, cmp);
        if (fuorsum == 1)
            people[fournum[0].xuhao].score = 95;
        else
        {
            for (int i = 0; i < fuorsum / 2; i++)
                people[fournum[i].xuhao].score = 95;
            for (int i = fuorsum / 2; i < fuorsum; i++)
                people[fournum[i].xuhao].score = 90;
        }

        sort(threenum, threenum + threesum, cmp);
        if (threesum == 1)
            people[threenum[0].xuhao].score = 85;
        else
        {
            for (int i = 0; i < threesum / 2; i++)
                people[threenum[i].xuhao].score = 85;
            for (int i = threesum / 2; i < threesum; i++)
                people[threenum[i].xuhao].score = 80;
        }
        sort(twonum, twonum + twosum, cmp);
        if (twosum == 1)
            people[twonum[0].xuhao].score = 75;
        else
        {
            for (int i = 0; i < twosum / 2; i++)
                people[twonum[i].xuhao].score = 75;
            for (int i = twosum / 2; i < twosum; i++)
                people[twonum[i].xuhao].score = 70;
        }
        sort(onenum, onenum + onesum, cmp);
        if (onesum == 1)
            people[onenum[0].xuhao].score = 65;
        else
        {
            for (int i = 0; i < onesum / 2; i++)
                people[onenum[i].xuhao].score = 65;
            for (int i = onesum / 2; i < onesum; i++)
                people[onenum[i].xuhao].score = 60;
        }
        for (int i = 0; i < n - 1; i++)
            cout << people[i].score << endl;
        cout << people[n - 1].score;
        cin >> n;
        cout << endl
             << endl;
        if (n == -1)
            break;
    }

    return 0;
}