/*
 * @Author: KendrickKan 
 * @Date: 2020-09-26 19:43:00 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-09-26 19:51:17
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[105];
    bool flag = 0;
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        if ((a[i] - a[i - 1]) != 1 && (a[i] != 1))
            flag = 1;
    }
    if (flag != 0)
        cout << "-1" << endl;
    else
    {
        cout << a[0] << " " << a[0] + n - 1 << endl;
    }

    return 0;
}