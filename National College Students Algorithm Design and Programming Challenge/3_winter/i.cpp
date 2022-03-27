#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 5;
ll n, b[N], a[N], ans;
//b[i]表示二进制下的第i位
void update(ll x)
{
    for (ll i = 60; i >= 0; i--)
    {
        if ((x ^ (1ll << i)) < x)
        { //如果x在二进制表示下含有第i位
            if (b[i])
                x ^= b[i]; //如果b[i]存在则让x^b[i],
            //因为之前b[i]也是由已经保存过的a[]数组贡献的
            //所以，这样异或x可以看作x于之前的a[]数组进行异或
            //然后一直异或到为0或者当前b[i]还没有被赋值
            else
            {
                b[i] = x;
                break;
            } //否则b[i]赋值为x,
              //表示当前二进制下的第i位可以被异或出来，且x的最高位就是i
        }
    }
}

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(a[i]);
    } //读入数据对于每一个数字都下放来维护b[i]
    for (ll i = 60; i >= 0; i--)
        if ((ans ^ (1ll << i)) > ans)
            ans ^= b[i];
    //贪心的过程，ans看作一个二进制数，从高位开始，如果b[i]存在，
    //肯定优先跟b[i]异或，倒着让小值不会影响到大值
    cout << ans << endl;
    return 0;
}
