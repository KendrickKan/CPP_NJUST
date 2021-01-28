/*
 * @Author: KendrickKan 
 * @Date: 2020-12-19 19:04:50 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-12-19 19:05:16
 */
//ctrl alt i new-head
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem0(a) memset(a, 0, sizeof(a))
#define memfu1(a) memset(a, -1, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define EPS 1e-10
const int MOD = 1e9 + 7;
//INT_MAX <limits>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main()
{
    FastIO;
    int a[10005];
    mem0(a);
    a[0] = 1;
    a[1] = 4;
    a[2] = 4;
    rep(i, 3, 10005)
    {
        if (i % 2 == 1)
        {
            a[i] = a[i - 2] + (i / 2 + 1) * 4;
        }
        else
        {
            a[i] = i * 4 - (i / 2) * 4 + a[i - 4];
            //or a[i]=(i/2+1)*(i/2+1);
        }
    }
    int n;
    cin >> n;
    cout << a[n];
    return 0;
}