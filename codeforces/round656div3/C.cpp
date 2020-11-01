#include <iostream>
using namespace std;
int main()
{
    int t, n;
    bool bo;
    cin >> t;
    int a[200001] = {0};
    while (t--)
    {
        bo = true;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 0; i--)
        {
            if (bo)
                if (a[i - 1] < a[i])
                    bo = false;
            if (!bo)
                if (a[i - 1] > a[i])
                {
                    cout << i << endl;
                    break;
                }
            if(i==0)
                cout<<'0'<<endl;
        }
    }

    return 0;
}