#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << "Case " << i << ": ";
        if (a == b)
        {
            if (a == 1)
                cout << "Habb Yakk" << endl;
            else if (a == 2)
                cout << "Dobara" << endl;
            else if (a == 3)
                cout << "Dousa" << endl;
            else if (a == 4)
                cout << "Dorgy" << endl;
            else if (a == 5)
                cout << "Dabash" << endl;
            else if (a == 6)
                cout << "Dosh" << endl;
        }
        else
        {
            int max, min;
            if (a > b)
                max = a, min = b;
            else
                max = b, min = a;
            if (max == 6 && min == 5)
                cout << "Sheesh Beesh" << endl;
            else
            {
                if (max == 2)
                    cout << "Doh ";
                else if (max == 3)
                    cout << "Seh ";
                else if (max == 4)
                    cout << "Ghar ";
                else if (max == 5)
                    cout << "Bang ";
                else
                    cout << "Sheesh ";
                if (min == 1)
                    cout << "Yakk" << endl;
                else if (min == 2)
                    cout << "Doh" << endl;
                else if (min == 3)
                    cout << "Seh" << endl;
                else if (min == 4)
                    cout << "Ghar" << endl;
                else
                    cout << "Bang" << endl;
            }
        }
    }
    return 0;
}