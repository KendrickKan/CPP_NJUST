#include <cstdio>
#include <vector>
using namespace std;
int P[1000][9];                                     //方式 i 中第 j 行皇后的列位置为 P[i][j]
int tmp[8];                                         //当前方式中第 i 行皇后的列位置为 tmp[i]
int n = 0;                                          //方式数初始化
bool col[8] = {0}, left[15] = {0}, right[15] = {0}; //所有列和左右对角线未被选中
void func(int r)                                    //从 r 行出发，递归计算所有方案中 8 皇后的位置
{
    if (r == 8)
    {                               //若搜索了所有行
        for (int i = 0; i < 8; ++i) //记下当前方式中 8 个皇后的列位置
            P[n][i] = tmp[i];
        ++n;    //方式数+1
        return; //回溯
    }
    for (int c = 0; c < 8; ++c)
    {                         //依次搜索 r 行的每一列
        int ld = (c - r) + 7; //计算(r, c)的左右对角线序号
        int rd = c + r;
        if (!col[c] && !left[ld] && !right[rd])
        { //若第 c 列和左右对角线未选中，则选中 c 列和左右对角线
            col[c] = 1, left[ld] = 1, right[rd] = 1;
            tmp[r] = c;                              //(r, c)置放皇后
            func(r + 1);                             //递归下一行
            col[c] = 0, left[ld] = 0, right[rd] = 0; //撤去第 c 列和左右对角线的选中标志
        }
    }
}
int main()
{
    func(0); //从 0 行出发，自上而下递归计算所有方案中的 8 皇后位置

    int Case;
    int board[8][8];
    scanf("%d", &Case); //输入棋盘数
    while (Case--)
    {
        for (int i = 0; i < 8; ++i) //输入当前棋盘中每格的数字
            for (int j = 0; j < 8; ++j)
                scanf("%d", &board[i][j]);

        int ans = 0;

        for (int i = 0; i < n; ++i)
        {                               //依次搜索每个方式
            int sum = 0;                //第 i 个方式的得分初始化
            for (int j = 0; j < 8; ++j) //搜索每一行，累计第 i 个方式的得分
                sum += board[j][P[i][j]];
            if (sum > ans)
                ans = sum; //若当前方式的得分目前最高，则调整棋盘最高得分
        }
        printf("%5d\n", ans); //输出当前棋盘的最高得分
    }
}