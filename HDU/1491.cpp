#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int month, day;
        cin >> month >> day;
        if (month > 10)
            cout << "What a pity, it has passed!" << endl;
        else if (month == 10)
        {
            if (day == 21)
                cout << "It's today!!" << endl;
            else if (day > 21)
                cout << "What a pity, it has passed!" << endl;
            else
            {
                cout << 21 - day << endl;
            }
        }
        else
        {
            int ans = 21;
            if (month == 2)
                ans += 28 - day;
            else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8)
                ans += 31 - day;
            else
                ans += 30 - day;
            for (int i = month + 1; i < 10; i++)
            {
                if (i == 2)
                    ans += 28;
                else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8)
                    ans += 31;
                else
                    ans += 30;
            }
            cout << ans << endl;
        }
    }

    return 0;
}