#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    string str;
    while (t--)
    {
        cin >> str;
        ll sum = 1;
        int a = 0, b = str.length() - 1;
        while (str[a] == '?')
            a++;
        while (str[b] == '?')
            b--;
        for (int i = a; i < b; i++)
        {
            if (str[i] == '?')
            {
                int x = i;
                while (str[x] == '?')
                {
                    x++;
                }
                if (str[i - 1] != str[x])
                    sum = (sum * ((x - i + 1) % N)) % N;
                i = x;
            }
        }
        cout << sum << endl;
    }
    return 0;
}