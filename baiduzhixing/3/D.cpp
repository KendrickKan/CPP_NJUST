#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//int you[100005];
//int zuo[100005];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
      //  memset(you, 0, sizeof(you));
      //  memset(zuo, 0, sizeof(zuo));
        ll n;
        cin >> n;
        ll maxyou, maxzuo;
        maxyou = maxzuo = 0;
        for (int i = 0; i < n; i++)
        {
            int id;
            ll location;
            cin >> id >> location;
            if (id == 1)
            {
              //  you[location] = 1;
                if (location > maxyou)
                    maxyou = location;
            }
            else
            {
             //   zuo[location] = 1;
                if (location > maxzuo)
                    maxzuo = location;
            }
        }
        if (maxyou >= (maxzuo + 2))
            cout << maxyou + 1 << endl;
        else if (maxzuo >= maxyou)
            cout << maxzuo + 2 << endl;
        else
        {
            if (maxyou == 1)
                cout << 2 << endl;
            else
            {
                cout << maxzuo + 3 << endl;
            }
        }
    }

    return 0;
}