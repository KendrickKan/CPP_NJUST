#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string quzero(string a)
{
    bool flag = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] == '.')
        {
            flag = 1;
            break;
        }
    int num = a.length() - 1;
    if (flag)
    {
        for (int i = num; i >= 0; i--)
        {
            if (a[i] != '0')
                break;
            else
                a.pop_back();
        }
    }
    if (a[a.length() - 1] == '.')
        a.pop_back();
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    string a, b;
    while (cin >> a >> b)
    {
        a = quzero(a);
        b = quzero(b);
        if (a == b)
            cout << "YES";
        else
        {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}