#include <bits/stdc++.h>
using namespace std;
int fastpower(long long b, long long p, long long k)
{
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    long long b, p, k;
    cin >> b >> p >> k;
    long long ans = 0;
    while (p > 0) //快速幂
    {
        if (p % 2 != 0)
            ans = ans * b % k; //如果p为单数，乘到ans里面去，然后取模
        b = b * b % k;         //每次运算都取模
        p = p >> 1;            //用位运算除2，可能会快一点
    }
    cout << ans << endl;
    return 0;
}