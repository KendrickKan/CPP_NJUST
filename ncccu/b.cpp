#include <iostream>
using namespace std;
int a[1005];
int b[1005];
int c[1005];
int main()
{
    int n;
    cin >> n;
    int i = 0;
    long long sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i] * a[i] * a[i];
        sum += b[i];
    }
    int j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == sum - a[i] * a[i] * a[i])
        {
            c[j] = a[i];
            j++;
        }
    }
    for (i = 0; i < j - 1; i++)
    {
        cout << c[i] << " ";
    }
    cout << c[j - 1] << endl;

    return 0;
}