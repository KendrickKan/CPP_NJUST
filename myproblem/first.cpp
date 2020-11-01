#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct kstudent
{
    string kname;
    int kaveGPA;
    int kaveScore;
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
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
    {
        float kcredit[10005];
        kstudent ks[10005];
        memset(kcredit, 0, sizeof(kcredit));
        memset(ks, 0, sizeof(ks));
        int n, m;
        cin >> n >> m;
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
            float onetotalscore = 0;
            float onetotalGPA = 0;
            for (int j = 0; j < m; j++)
            {
                string fen;
                cin >> fen;
                float defen = changetonum(fen);
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
        cout << "Case " << q << ':' << endl;
        for (int i = 0; i < n; i++)
            cout << ks[i].kname << endl;
        cout << endl;
    }
    return 0;
}