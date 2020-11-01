#include <iostream>
#include <string>
using namespace std;
struct people
{
    int p;
    string t;
    int xuhao;
};
bool comparetime(people a, people b)
{
    if (a.p < b.p)
        return true;
    else if (a.p > b.p)
        return false;
    else
    {
        if (a.t[0] > b.t[0])
            return true;
        else if (a.t[0] < b.t[0])
            return false;
        else
        {
            if (a.t[1] > b.t[1])
                return true;
            else if (a.t[1] < b.t[1])
                return false;
            else
            {
                if (a.t[3] > b.t[3])
                    return true;
                else if (a.t[3] < b.t[3])
                    return false;
                else
                {
                    if (a.t[4] > b.t[4])
                        return true;
                    else if (a.t[4] < b.t[4])
                        return false;
                    else
                    {
                        if (a.t[6] > b.t[6])
                            return true;
                        else if (a.t[6] < b.t[6])
                            return false;
                        else
                        {
                            if (a.t[7] > b.t[7])
                                return true;
                            else
                                return false;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    people a[130];
    int n, g, s, c, m;
    while (cin >> n >> g >> s >> c >> m && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].p >> a[i].t;
            a[i].xuhao = i + 1;
        }
        people temp;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (comparetime(a[j], a[j + 1]))
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        int x;
        for (int i = 0; i < n; i++)
            if (a[i].xuhao == m)
                x = i + 1;
        if (x <= g)
            cout << "Accepted today? I've got a golden medal :)" << endl;
        else if (x > g && x <= (g + s))
            cout << "Accepted today? I've got a silver medal :)" << endl;
        else if (x > (g + s) && x <= (g + s + c))
            cout << "Accepted today? I've got a copper medal :)" << endl;
        else
            cout << "Accepted today? I've got an honor mentioned :)" << endl;
    }
    return 0;
}