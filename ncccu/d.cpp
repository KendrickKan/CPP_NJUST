#include <iostream>
#include <string>
using namespace std;
struct knode
{
    string name1;
    string name2;
    int flag;
};
knode a[405];
string ans[405];
int main()
{
    string str;
    cin >> str;
    int i = 0;
    int num = 0;
    for (i = 0; i < 405; i++)
        a[i].flag = 0;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '[')
        {
            int j = i + 1;
            for (j; j < str.length(); j++)
            {
                if (str[j] != '-')
                    a[num].name1 += str[j];
                else
                {
                    i = j;
                    break;
                }
            }
        }
        if (str[i] == '>')
        {
            int j = i + 1;
            for (j; j < str.length(); j++)
            {
                if (str[j] != ']')
                    a[num].name2 += str[j];
                else
                {
                    num++;
                    i = j;
                    break;
                }
            }
        }
    }
    string cmp;
    cin >> cmp;
    int x = 0;
    int j;
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (a[i].name1 == a[j].name2 && a[i].name2 == a[j].name1 && a[j].flag == false)
            {
                // (a[i].name1 == cmp || a[i].name2 == cmp)
                if (a[i].name1 == cmp)
                {
                    ans[x] = a[i].name2;
                    x++;
                }
                else if (a[i].name2 == cmp)
                {
                    ans[x] = a[i].name1;
                    x++;
                }
                a[j].flag = true;
            }
        }
    }
    for (i = 0; i < x - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[x - 1] << endl;
    return 0;
}