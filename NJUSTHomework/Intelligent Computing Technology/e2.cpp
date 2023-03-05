#include <bits/stdc++.h>
using namespace std;
int chessboard[5][5] = {0}; // 0表示未下棋，1表示AI，2表示人类
void printchessboard()
{
    cout << "  0 1 2 3 4" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 5; j++)
        {
            if (chessboard[i][j] == 0)
                cout << "□ ";
            else if (chessboard[i][j] == 1)
                cout << "● ";
            else
                cout << "x ";
        }
        cout << endl;
    }
    cout << endl;
}
// 判断AI是否获胜 返回值为1表示AI获胜，返回值为2表示人类获胜，返回值为0表示未决出胜负
int check()
{
    // 横向
    for (int i = 0; i < 5; i++)
    {
        bool flag1 = true;
        bool flag2 = true;
        for (int j = 0; j < 5; j++)
        {
            if (chessboard[i][j] != 1)
                flag1 = false;
            if (chessboard[i][j] != 2)
                flag2 = false;
        }
        if (flag1)
            return 1;
        if (flag2)
            return 2;
    }
    // 纵向
    for (int i = 0; i < 5; i++)
    {
        bool flag1 = true;
        bool flag2 = true;
        for (int j = 0; j < 5; j++)
        {
            if (chessboard[j][i] != 1)
                flag1 = false;
            if (chessboard[j][i] != 2)
                flag2 = false;
        }
        if (flag1)
            return 1;
        if (flag2)
            return 2;
    }
    // 左上到右下
    bool flag1 = true;
    bool flag2 = true;
    for (int i = 0; i < 5; i++)
    {
        if (chessboard[i][i] != 1)
            flag1 = false;
        if (chessboard[i][i] != 2)
            flag2 = false;
    }
    if (flag1)
        return 1;
    if (flag2)
        return 2;
    // 右上到左下
    flag1 = true;
    flag2 = true;
    for (int i = 0; i < 5; i++)
    {
        if (chessboard[i][4 - i] != 1)
            flag1 = false;
        if (chessboard[i][4 - i] != 2)
            flag2 = false;
    }
    if (flag1)
        return 1;
    if (flag2)
        return 2;
    // 未决出胜负
    return 0;
}
// 估价函数，对AI估价，返回值越大，AI越有利
int e()
{
    int ea = 0;
    int eb = 0;
    int tempchessboard1[5][5] = {0};
    int tempchessboard2[5][5] = {0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tempchessboard1[i][j] = chessboard[i][j];
            tempchessboard2[i][j] = chessboard[i][j];
            if (tempchessboard1[i][j] == 0)
                tempchessboard1[i][j] = 1;
            if (tempchessboard2[i][j] == 0)
                tempchessboard2[i][j] = 2;
        }
    }
    // 横向
    for (int i = 0; i < 5; i++)
    {
        bool flag1 = true;
        bool flag2 = true;
        for (int j = 0; j < 5; j++)
        {
            if (tempchessboard1[i][j] != 1)
                flag1 = false;
            if (tempchessboard2[i][j] != 2)
                flag2 = false;
        }
        if (flag1)
            ea += 1;
        if (flag2)
            eb += 1;
    }
    // 纵向
    for (int i = 0; i < 5; i++)
    {
        bool flag1 = true;
        bool flag2 = true;
        for (int j = 0; j < 5; j++)
        {
            if (tempchessboard1[j][i] != 1)
                flag1 = false;
            if (tempchessboard2[j][i] != 2)
                flag2 = false;
        }
        if (flag1)
            ea += 1;
        if (flag2)
            eb += 1;
    }
    // 左上到右下
    bool flag1 = true;
    bool flag2 = true;
    for (int i = 0; i < 5; i++)
    {
        if (tempchessboard1[i][i] != 1)
            flag1 = false;
        if (tempchessboard2[i][i] != 2)
            flag2 = false;
    }
    if (flag1)
        ea += 1;
    if (flag2)
        eb += 1;
    // 右上到左下
    flag1 = true;
    flag2 = true;
    for (int i = 0; i < 5; i++)
    {
        if (tempchessboard1[i][4 - i] != 1)
            flag1 = false;
        if (tempchessboard2[i][4 - i] != 2)
            flag2 = false;
    }
    if (flag1)
        ea += 1;
    if (flag2)
        eb += 1;
    return ea - eb;
}
int next_step[2]; // AI下一步的坐标
// 博弈树极大极小值搜索 α-β剪枝
int alpha_beta_min_max_search(bool is_AI, int depth, int alpha, int beta)
{
    if (check() != 0 || depth == 0)
        return e();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (chessboard[i][j] == 0)
            {
                chessboard[i][j] = is_AI ? 1 : 2;
                int value = alpha_beta_min_max_search(!is_AI, depth - 1, alpha, beta);
                chessboard[i][j] = 0;
                if (is_AI)
                {
                    if (value > alpha)
                    {
                        alpha = value;
                        if (depth == 3)
                        {
                            next_step[0] = i;
                            next_step[1] = j;
                        }
                    }
                }
                else
                {
                    if (value < beta)
                        beta = value;
                }
                if (alpha >= beta)
                    return is_AI ? alpha : beta;
            }
        }
    }
    return is_AI ? alpha : beta;
}
int main()
{
    int x, y;
    cout << "欢迎来到五子棋游戏！\n";
    printchessboard();
    while (1)
    {
        printf("请输入坐标：x=0~4,y=0~4 \n");
        scanf("%d %d", &x, &y);
        chessboard[x][y] = 2;
        printchessboard();
        if (check() == 2)
        {
            printf("你赢了！\n");
            break;
        }
        cout << "AI正在思考...\n";
        alpha_beta_min_max_search(true, 3, -100000, 100000);
        chessboard[next_step[0]][next_step[1]] = 1;
        printchessboard();
        if (check() == 1)
        {
            printf("你输了！\n");
            break;
        }
    }
    return 0;
}