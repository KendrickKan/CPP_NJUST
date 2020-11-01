#include <iostream>
using namespace std;
int main()
{
    int n, x, thissum = 0, maxsum = 0;
    cin >> n;
    while (n--)
    {
        cin >> x;
        thissum += x;
        if (thissum > maxsum)
            maxsum = thissum;
        else if (thissum < 0)
            thissum = 0;
    }
    cout << maxsum;
    return 0;
}