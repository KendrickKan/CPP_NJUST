#include <iostream>
#include <string.h>
using namespace std;
int map[101][101];
int visited[101][101];
int search(int r, int c, int x, int y)
{
    int num1, num2, max;
    if (visited[x][y] !=0)
    {
        return visited[x][y];
    }
        else

        {
            
            if (x == r - 1 && y == c - 1)
                return 0;
            else if ((x + 1 < r) && (y + 1 < c))
            {
                num1 = search(r, c, x + 1, y), num2 = search(r, c, x, y + 1);
                max = num1 > num2 ? num1 : num2;
            }
            else if ((x > r - 2) && (y + 1 < c))
                max = search(r, c, x, y + 1);
            else if ((x + 1 < r) && (y > c - 2))
                max = search(r, c, x + 1, y);
            visited[x][y]=map[x][y] + max;
        }

    return map[x][y] + max;
}
int main()
{
    int n, r, c, cishu = 1;
    cin >> n;
    char p, e;
    while (n--)
    {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                if (i == 0 && j == 0)
                {
                    cin >> p;
                    continue;
                }
                if (i == r - 1 && j == c - 1)
                {
                    cin >> e;
                    continue;
                }
                cin >> map[i][j];
            }
        memset(visited, 0, sizeof(visited));
        map[0][0] = map[r - 1][c - 1] = 0;
        cout << "Game Board #" << cishu << ": ";
        cout << search(r, c, 0, 0) << endl
             << endl;
        cishu++;
    }

    return 0;
}