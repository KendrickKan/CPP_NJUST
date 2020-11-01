#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int D, I;
        cin >> D >> I;
        int k = 1;
        for (int i = 0; i < D - 1; i++)
        {
            if (I % 2 == 1)
            {
                k = k * 2;
                I = (I + 1) / 2;
            }
            else
            {
                k = k * 2 + 1;
                I = I / 2;
            }
        }
        cout << k << endl;
    }
    cin >> n;
    return 0;
}
