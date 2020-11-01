#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 200
bool judge(int *a, int x, int num)
{
    for (int i = 0; i < num; i++)
        if (x == a[i])
            return false;
    return true;
}
int main()
{
    int t, n, num;
    cin >> t;
    int a[MAXSIZE], b[MAXSIZE];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        num = 0;
        cin >> n;
        for (int i = 0; i < n * 2; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n * 2; i++)
        {
            if (judge(b, a[i], num))
            {
                b[num] = a[i];
                num++;
            }
            if (num == n)
                break;
        }
        for (int i = 0; i < n; i++)
            cout << b[i] << ' ';
        cout << endl;
    }

    return 0;
}