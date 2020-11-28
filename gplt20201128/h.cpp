#include <bits/stdc++.h>
using namespace std;
struct node
{
    int num;
    bool see;
};
int main()
{
    int ans[25];
    ans[6] = 10000;
    ans[7] = 36;
    ans[8] = 720;
    ans[9] = 360;
    ans[10] = 80;
    ans[11] = 252;
    ans[12] = 108;
    ans[13] = 72;
    ans[14] = 54;
    ans[15] = 180;
    ans[16] = 72;
    ans[17] = 180;
    ans[18] = 119;
    ans[19] = 36;
    ans[20] = 306;
    ans[21] = 1080;
    ans[22] = 144;
    ans[23] = 1800;
    ans[24] = 3600;
    node a[3][3];
    int b[9];
    memset(b, 0, sizeof(b));
    int tx, ty;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j].num;
            a[i][j].see = false;
            if (a[i][j].num == 0)
            {
                tx = i;
                ty = j;
            }
            else
                b[a[i][j].num - 1] = true;
        }
    for (int i = 0; i < 9; i++)
    {
        if (!b[i])
        {
            a[tx][ty].num = i + 1;
            a[tx][ty].see = true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << a[x - 1][y - 1].num << endl;
        a[x - 1][y - 1].see = true;
    }
    int tttt;
    cin >> tttt;
    //cout << tttt << endl;
    int anssum = 0;
    if (tttt == 1)
    {
        anssum = a[0][0].num + a[0][1].num + a[0][2].num;
        a[0][0].see = true;
        a[0][1].see = true;
        a[0][2].see = true;
    }
    else if (tttt == 2)
    {
        anssum = a[1][0].num + a[1][1].num + a[1][2].num;
        a[1][0].see = true;
        a[1][1].see = true;
        a[1][2].see = true;
    }
    else if (tttt == 3)
    {
        anssum = a[2][0].num + a[2][1].num + a[2][2].num;
        a[2][0].see = true;
        a[2][1].see = true;
        a[2][2].see = true;
    }
    else if (tttt == 4)
    {
        anssum = a[0][0].num + a[1][0].num + a[2][0].num;
        a[0][0].see = true;
        a[1][0].see = true;
        a[2][0].see = true;
    }
    else if (tttt == 5)
    {
        anssum = a[0][1].num + a[1][1].num + a[2][1].num;
        a[0][1].see = true;
        a[1][1].see = true;
        a[2][1].see = true;
    }
    else if (tttt == 6)
    {
        anssum = a[0][2].num + a[1][2].num + a[2][2].num;
        a[0][2].see = true;
        a[1][2].see = true;
        a[2][2].see = true;
    }
    else if (tttt == 7)
    {
        anssum = a[0][0].num + a[1][1].num + a[2][2].num;
        a[0][0].see = true;
        a[1][1].see = true;
        a[2][2].see = true;
    }
    else if (tttt == 8)
    {
        anssum = a[0][2].num + a[1][1].num + a[2][0].num;
        a[0][2].see = true;
        a[1][1].see = true;
        a[2][0].see = true;
    }
    // int anssum = 0;
    // for (int i = 0; i < 3; i++)
    //     for (int j = 0; j < 3; j++)
    //     {
    //         if (a[i][j].see)
    //             anssum += a[i][j].num;
    //     }
    //cout << anssum << endl;
    cout << ans[anssum];
    return 0;
}