#include <bits/stdc++.h>
using namespace std;
char s[28] = {'_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.'};
int main()
{
    char str[80];
    int k;
    int i, j, n, m;
    int p[80];
    while (cin >> k)
    {
        if (k == 0)
            break;
        cin >> str;
        int len = strlen(str);
        for (i = 0; i < len; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                n = str[i] - 96;
            else if (str[i] == '_')
                n = 0;
            else
                n = 27;
            m = (k * i) % len;
            for (j = 0; j < 28; j++)
            {
                if (((j - i) + 5 * 28) % 28 == n)
                {
                    p[m] = j;
                    break;
                }
            }
        }
        for (i = 0; i < len; i++)
            cout << s[p[i]];
        cout << endl;
    }
    return 0;
}