#include <iostream>
#include <cmath>
using namespace std;
char fractalmap[1026][1026];
void printmap(int n, int x, int y)
{
    int m;
    if(n==1)
    {
        fractalmap[x][y] = 'X';
        fractalmap[x][y+1] = 'X';
        fractalmap[x+1][y] = 'X';
        fractalmap[x+1][y+1] = 'X';
        return;
    }
    m=pow(2.0,n-1);
    printmap(n-1,m+x,y-m/2);//leftdown
    printmap(n-1,m+x,y+m/2);//rightdown
    printmap(n-1,x,y);//head
}
int main()
{
    int t, m, n,x=1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout<<"Triangle #"<<x<<":"<<endl;
        m = pow(2.0, n);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                fractalmap[i][j] = ' ';
        printmap(n, 1, m/2);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << fractalmap[i][j];
            cout << endl;
        }
        cout<<endl;
        x++;
    }

    return 0;
}