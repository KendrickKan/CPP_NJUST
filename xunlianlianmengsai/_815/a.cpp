#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.length();
    string s1;
    for (int l = 0; l < n; ++l)
    {
        cin >> s1;
        int len1 = s1.length();
        bool flag = false;
        int i = 0, j = 0;
        if (s == s1)
            flag = true;
        while (i < len && j < len1)
        {
            if (s[i] != s1[j] || (s[i] == s1[j] && s[i] <= '9' && s[i] >= '0'))
            {
                if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
                {
                    if (s1[i] > s[i])
                    {
                        flag = true;
                    }
                    break;
                }
                else if (s[i] >= '0' && s[i] <= '9')
                {
                    if (s1[i] >= '0' && s1[i] <= '9')
                    {
                        int a = 0, b = 0;
                        for (; i < len; ++i)
                        {
                            if (s[i] >= '0' && s[i] <= '9')
                                a = a * 10 + s[i] - '0';
                            else
                                break;
                        }
                        for (; j < len1; ++j)
                        {
                            if (s1[j] >= '0' && s1[j] <= '9')
                                b = b * 10 + s1[j] - '0';
                            else
                                break;
                        }
                        --i, --j;
                        if (a < b)
                        {
                            flag = true;
                            break;
                        }
                        else if (a > b)
                            break;
                    }
                    else
                        flag = true;
                }
            }
            if (i == len - 1 && j < len1)
                flag = true;
            ++i, ++j;
        }
        if (flag)
            cout << "+" << endl;
        else
            cout << "-" << endl;
    }
    return 0;
}