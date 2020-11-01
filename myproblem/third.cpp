#include <bits/stdc++.h>
using namespace std;
char fractalmap[731][731];
void printmap(int n, int x, int y, char p)
{
    int m;
    if (n == 1)
    {
        fractalmap[x][y] = p;
        return;
    }
    m = pow(3.0, n - 2);
    printmap(n - 1, m + x, y, p);         //up
    printmap(n - 1, x, y + m, p);         //left
    printmap(n - 1, m * 2 + x, y + m, p); //right
    printmap(n - 1, m + x, y + 2 * m, p); //down
}
int main()
{
    int m, n;
    char p;
    cin >> n;
    cin >> p;
    m = pow(3.0, n - 1);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            fractalmap[i][j] = ' ';
    printmap(n, 1, 1, p);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << fractalmap[i][j];
        cout << endl;
    }
    return 0;
}