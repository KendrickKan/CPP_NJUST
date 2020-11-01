#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        int x;
        int thissum = 0, maxsum = -1005, num;
        cin >> x;
        int begin, last;
        int temp = 1;
        begin = last = 1;
        for (int i = 1; i <= x; i++)
        {
            cin >> num;
            thissum += num;
            if (thissum > maxsum)
            {
                maxsum = thissum;
                last = i;
                begin = temp;
            }
            if (thissum < 0)
            {
                thissum = 0;
                temp = i + 1;
            }
        }
        cout << "Case " << j << ':' << endl;
        cout << maxsum << ' ' << begin << ' ' << last << endl;
        if (j < t)
            cout << endl;
    }
    return 0;
}