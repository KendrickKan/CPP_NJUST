#include <iostream>
#include <cmath>
using namespace std;
char fractalmap[731][731];
void printmap(int n, int x, int y)
{
    int m;
    if (n == 1)
    {
        fractalmap[x][y] = 'X';
        return;
    }
    m = pow(3.0, n - 2);
    printmap(n - 1, x, y);
    printmap(n - 1, x, y + 2 * m);
    printmap(n - 1, x + m, y + m);
    printmap(n - 1, x + 2 * m, y);
    printmap(n - 1, x + 2 * m, y + 2 * m);
}
int main()
{
    int n, m;
    cin >> n;
    while (n > 0)
    {
        m = pow(3.0, n - 1);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                fractalmap[i][j] = ' ';
        printmap(n, 1, 1);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << fractalmap[i][j];
            cout << endl;
        }
        cout << '-' << endl;
        cin >> n;
    }

    return 0;
}