#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct kstudent
{
    string kname;
    int kaveGPA;
    int kaveScore;
    int special, first, secondandthird;
    int ifhaveprize;
};
float changetonum(string a)
{
    if (a == "A")
        return 90.0;
    else if (a == "B")
        return 80.0;
    else if (a == "C")
        return 70.0;
    else if (a == "D")
        return 60.0;
    else if (a == "E")
        return 0;
    else
    {
        if (a.length() == 3)
            return 100.0;
        else
        {
            float x;
            x += (a[0] - '0') * 10.0 + (a[1] - '0') * 1.0;
            return x;
        }
    }
}
float changescoretoGPA(float a)
{
    if (a >= 90.0)
        return 4.0;
    else if (a >= 85.0 && a < 90.0)
        return 3.7;
    else if (a >= 82.0 && a < 85.0)
        return 3.3;
    else if (a >= 78.0 && a < 82.0)
        return 3.0;
    else if (a >= 75.0 && a < 78.0)
        return 2.7;
    else if (a >= 72.0 && a < 75.0)
        return 2.3;
    else if (a >= 68.0 && a < 72.0)
        return 2.0;
    else if (a >= 64.0 && a < 68.0)
        return 1.5;
    else if (a >= 60.0 && a < 64.0)
        return 1.0;
    else
        return 0;
}
bool cmp(kstudent a, kstudent b)
{
    if (a.kaveGPA != b.kaveGPA)
        return a.kaveGPA > b.kaveGPA;
    else
    {
        if (a.kaveScore != b.kaveScore)
            return a.kaveScore > b.kaveScore;
        else
            return a.kname < b.kname;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    float kcredit[10005];
    kstudent ks[10005];
    string specialname[10005];
    string firstname[10005];
    string secondname[10005];
    string thirdname[10005];
    memset(kcredit, 0, sizeof(kcredit));
    memset(ks, 0, sizeof(ks));
    memset(specialname, 0, sizeof(specialname));
    memset(firstname, 0, sizeof(firstname));
    memset(secondname, 0, sizeof(secondname));
    memset(thirdname, 0, sizeof(thirdname));
    int n, m;
    cin >> n >> m;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    float totalcredit = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> kcredit[i];
        totalcredit += kcredit[i];
    }
    for (int i = 0; i < n; i++)
    {
        string ksname;
        cin >> ksname;
        ks[i].kname = ksname;
        ks[i].special = 1;
        ks[i].first = 1;
        ks[i].secondandthird = 1;
        float onetotalscore = 0;
        float onetotalGPA = 0;
        for (int j = 0; j < m; j++)
        {
            string fen;
            cin >> fen;
            float defen = changetonum(fen);
            if (defen < 80.0)
                ks[i].special = 0;
            if (defen < 75.0)
                ks[i].first = 0;
            if (defen < 60.0)
                ks[i].secondandthird = 0;
            float GPA = changescoretoGPA(defen);
            onetotalGPA += GPA * kcredit[j];
            onetotalscore += defen * kcredit[j];
        }
        float xgpa, yscore;
        xgpa = onetotalGPA / totalcredit;
        yscore = onetotalscore / totalcredit;
        ks[i].kaveGPA = (xgpa + 0.005) * 100;
        ks[i].kaveScore = (yscore + 0.005) * 100;
    }
    sort(ks, ks + n, cmp);
    int specialnum = 0, firstnum = 0, secondnum = 0, thirdnum = 0;
    for (int i = 0; i < n; i++)
    {
        if (specialnum < a && ks[i].special == 1 && ks[i].ifhaveprize == 0)
        {
            specialname[specialnum] = ks[i].kname;
            specialnum++;
            ks[i].ifhaveprize = 1;
        }
        if (firstnum < b && ks[i].first == 1 && ks[i].ifhaveprize == 0)
        {
            firstname[firstnum] = ks[i].kname;
            firstnum++;
            ks[i].ifhaveprize = 1;
        }
        if (secondnum < c && ks[i].secondandthird == 1 && ks[i].ifhaveprize == 0)
        {
            secondname[secondnum] = ks[i].kname;
            secondnum++;
            ks[i].ifhaveprize = 1;
        }
        if (thirdnum < d && ks[i].secondandthird == 1 && ks[i].ifhaveprize == 0)
        {
            thirdname[thirdnum] = ks[i].kname;
            thirdnum++;
            ks[i].ifhaveprize = 1;
        }
    }
    cout << "SPECIAL:" << endl;
    if (specialnum != 0)
    {
        for (int i = 0; i < specialnum; i++)
            cout << specialname[i] << endl;
    }
    else
        cout << 0 << endl;
    cout << "FIRST:" << endl;
    if (firstnum != 0)
    {
        for (int i = 0; i < firstnum; i++)
            cout << firstname[i] << endl;
    }
    else
        cout << 0 << endl;
    cout << "SECOND:" << endl;
    if (secondnum != 0)
    {
        for (int i = 0; i < secondnum; i++)
            cout << secondname[i] << endl;
    }
    else
        cout << 0 << endl;
    cout << "THIRD:" << endl;
    if (thirdnum != 0)
    {
        for (int i = 0; i < thirdnum; i++)
            cout << thirdname[i] << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}