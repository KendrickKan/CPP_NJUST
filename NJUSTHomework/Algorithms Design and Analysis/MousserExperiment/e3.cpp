#include <bits/stdc++.h>
using namespace std;
//使用邻接矩阵
int V; //节点个数
int E; //边条数
int g[100][100];
int pre[100]; //用来存每个节点的前一个结点
int dis[100];
bool choose[100]; //用来判断这个节点是否在集合中
bool ifchoose()
{
    for (int i = 0; i < V; i++)
    {
        if (choose[i] != 1)
            return true;
    }
    return false;
}
int main()
{
    scanf("%d", &V);
    scanf("%d", &E);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            g[i][j] = -1; //首先初始化，-1代表i和j之间没有路
        }
    }
    for (int i = 0; i < 100; i++)
    {
        dis[i] = 100000;
    }
    for (int i = 0; i < E; i++)
    {
        int a, b, c; // a和b之间有一条权值为c的边
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        g[a][b] = c;
        g[b][a] = c;
    }
    choose[0] = 1;              // 1代表在集合中
    for (int i = 1; i < V; i++) //把0节点放入集合，然后判断后面的节点和0节点的距离
    {
        if (g[0][i] != -1)
        {
            dis[i] = g[0][i];
            pre[i] = 0; // i节点的前一个节点为0节点
        }
    }
    while (ifchoose())//ifchoose()作用是判断所有节点是否都在集合中
    {
        int x, mindis = 100000;
        for (int i = 1; i < V; i++)
        {
            if (choose[i] != 1)
            {
                if (dis[i] < mindis)
                {
                    mindis = dis[i];
                    x = i;
                } //找距离集合最近的节点，更小就替换
            }
        }
        choose[x] = 1;
        //再遍历和x相连的每一条边
        for (int i = 0; i < V; i++)
        {
            if (choose[i] != 1 && (dis[x] + g[x][i] < dis[i]) && g[x][i] != -1)
            {
                dis[i] = dis[x] + g[x][i];//更新新的最短距离
                pre[i] = x;//更新这个节点的前一个节点
            }
        }
    }
    //输出
    for (int i = 1; i < V; i++)
    {
        printf("从0节点到%d节点的路径为：\n", i);
        int x = i;
        stack<int> sta;//栈 用来存放前一个节点序列
        sta.push(x);
        while (pre[x] != 0)
        {
            sta.push(pre[x]);//当前一个节点不是0 压栈
            x = pre[x];
        }
        sta.push(0);//压入第一个节点0
        while (!sta.empty())
        {
            int temp = sta.top();//栈顶元素
            printf("%d ", temp);
            sta.pop();//弹栈
        }
        printf("\n");
    }
    return 0;
}