#include <iostream>
#include <cmath>
using namespace std;
int beginscreen[3841][2161] = {0};
int afterscreen[3841][2161] = {0};
int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> beginscreen[i][j];
    
    return 0;
}