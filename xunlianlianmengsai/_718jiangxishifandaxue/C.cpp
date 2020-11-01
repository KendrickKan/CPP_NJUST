#include <iostream>
using namespace std;
int num[5];
bool judge()
{
    if (num[0] >= 0 && num[1] >= 0 && num[2] >= 0 && num[3] >= 0 && num[4] >= 0)
        return true;
    return false;
}
void solve()
{
    bool flag = judge();
    int x = 0;
    while (flag == false)
    {
        if (num[x % 5] < 0)
        {
            if (x % 5 == 0)
            {
                num[4] += num[0];
                num[1] += num[0];
            }
            else if (x % 5 == 4)
            {
                num[3] += num[4];
                num[0] += num[4];
            }
            else
            {
                num[x % 5 - 1] += num[x % 5];
                num[x % 5 + 1] += num[x % 5];
            }
            num[x % 5] *= -1;
        }
        x++;
        flag = judge();
    }
    for (int i = 0; i < 4; i++)
        cout << num[i] << " ";
    cout << num[4];
    cout << endl
         << endl;
}
int main()
{
    int n, x = 1;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++)
            cin >> num[i];
        cout << "Pentagon #" << x << ":" << endl;
        solve();
        x++;
    }

    return 0;
}