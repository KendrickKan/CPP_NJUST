#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        char ch;
        int n;
        cin >> ch >> n;
        int xiankuan, xiagao;
        xiankuan = n / 6 + 1;
        xiagao = n - 3 - (n - 3) / 2;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == n || i == n - xiagao - 1)
            {
                for (int j = 0; j < xiankuan; j++)
                    cout << ' ';
                for (int j = 0; j < xiagao; j++)
                    cout << ch;
                cout << endl;
            }
            else
            {
                for (int j = 0; j < xiankuan; j++)
                    cout << ch;
                for (int j = 0; j < xiagao; j++)
                    cout << ' ';
                for (int j = 0; j < xiankuan; j++)
                    cout << ch;
                cout << endl;
            }
        }
        if (t > 0)
            cout << endl;
    }

    return 0;
}