#include <iostream>
using namespace std;
long long a[100005];
bool flag[10005][10005];
int main()
{
    int n, m;
    long long x;
    cin >> n >> m;
    cin >> x;
    cin >> a[1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i + 2];
        // cout << (a[i + 1] ^ a[i + 2]);
        if ((a[i + 1] ^ a[i + 2]) == x)
            flag[i + 1][i + 2] = true;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (flag[j + 1][i + j] || flag[j + 2][i + j + 1] || ((a[j + 1] ^ a[i + j + 1]) == x))
            {
                flag[j + 1][i + j + 1] = true;
            }
            else
                flag[j + 1][i + j + 1] = false;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int c, d;
        cin >> c >> d;
        if (flag[c][d] == true)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}