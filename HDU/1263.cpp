#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct jiaoyi
{
    string fruitname = "", fruitpalce = ""; //在结构体中用string要赋空值不然会照成程序崩溃
    int num;
};
bool cmp(jiaoyi a, jiaoyi b)
{
    if (a.fruitpalce != b.fruitpalce)
        return a.fruitpalce < b.fruitpalce;
    else
    {
        return a.fruitname < b.fruitname;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int n;
    //string a[10];
    jiaoyi a[105];
    while (t--)
    {
        //memset(a, 0, sizeof(a));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string strname, strplace;
            cin >> strname;
            cin >> strplace;
            a[i].fruitname = strname;
            a[i].fruitpalce = strplace;
            cin >> a[i].num;
        }
        sort(a, a + n, cmp);
        string temp = "";
        a[n].fruitpalce = temp;
        a[n].fruitname = temp;
        string nowplace = temp;
        for (int i = 0; i < n; i++)
        {
            if (a[i].fruitpalce == a[i + 1].fruitpalce)
            {
                if (a[i].fruitname == a[i + 1].fruitname)
                    a[i + 1].num += a[i].num;
                else
                {
                    if (a[i].fruitpalce != nowplace)
                    {
                        cout << a[i].fruitpalce << endl;
                        nowplace = a[i].fruitpalce;
                    }
                    cout << "   |----" << a[i].fruitname << '(' << a[i].num << ')' << endl;
                }
            }
            else
            {
                if (a[i].fruitpalce != nowplace)
                {
                    cout << a[i].fruitpalce << endl;
                    nowplace = a[i].fruitpalce;
                }
                cout << "   |----" << a[i].fruitname << '(' << a[i].num << ')' << endl;
            }
        }
        if (t != 0)
            cout << endl;
    }

    return 0;
}