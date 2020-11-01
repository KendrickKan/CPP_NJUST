#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    while (cin >> s)
    {
        int f = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                cout << "Or not." << endl;
                f = 0;
                break;
            }
        }
        if (f)
        {
            cout << "Odd." << endl;
        }
    }
    return 0;
}
