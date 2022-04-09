#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    long long sumai = 0;
    long long sumaiai = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        sumai += x;
        sumaiai += (x * x);
    }
    ans = (sumai * sumai - sumaiai) / 2;
    cout << ans;
    return 0;
}