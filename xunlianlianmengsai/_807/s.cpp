#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int changestrtonum(string s)
{
    int num = 0;
    for (int i = 0; i < s.length(); i++)
        num = num * 10 + s[i] - '0';
    return num;
}
string changenumtostring(int num)
{
    string s;
    do
    {
        s += num % 10 + '0';
    } while ((num /= 10) > 0);
    reverse(s.begin(), s.end());
    return s;
}
bool judgezero(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0')
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    for (int i = changestrtonum(s) + 1;; i++)
    {
        string x = changenumtostring(i);
        if (judgezero(x))
        {
            cout << x << endl;
            break;
        }
    }
    return 0;
}