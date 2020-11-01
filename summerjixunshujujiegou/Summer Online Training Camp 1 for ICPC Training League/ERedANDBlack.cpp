#include <iostream>
#include <string.h>
using namespace std;
char mapch[25][25];
bool judge[25][25];
int m,n;
void searchmap(int x,int y,int &sumdata)
{
    if (x<0||x>=n||y<0||y>=m||mapch[x][y]=='#'||judge[x][y])
        return;
    judge[x][y]=true;
    sumdata++;
    searchmap(x-1,y,sumdata);
    searchmap(x+1,y,sumdata);
    searchmap(x,y-1,sumdata);
    searchmap(x,y+1,sumdata);
}
int main()
{
    cin>>m>>n;
    int sumdata=0;
    while (m||n)
    {
        int x,y;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>mapch[i][j];
                if(mapch[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
            }
        memset(judge, false, sizeof(judge));
        sumdata=0;
        searchmap(x,y,sumdata);
        cout<<sumdata<<endl;
        cin>>m>>n;
    }
    
    return 0;
}