#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
int f(int a)
{
    if (a == 2 || a == 6 || a == 10 || a == 14)
        return 1;
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int num = 0;
    while (n--)
    {
        int x;
        cin >> x;
        num += f(x);
    }
    cout << num;
    return 0;
}