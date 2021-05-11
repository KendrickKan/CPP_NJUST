#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
//邻接矩阵实现图
//该图是一个无向图
struct Graph
{
    int e[MAXN][MAXN];
    int edges;
    int ves;
    int DFSflag[MAXN];
    int BFSflag[MAXN];
};
Graph *createGraph(Graph *G)
{
    int vi;
    int vj;

    cout << "请输入图的顶点个数和边数" << endl;
    cout << "顶点个数:";
    cin >> G->ves;
    cout << "边数:";
    cin >> G->edges;

    //初始化
    for (int i = 0; i < G->ves; i++)
    {
        for (int j = 0; j < G->ves; j++)
        {
            G->e[i][j] = 0;
        }
        G->DFSflag[i] = 0; //标识全部置0,表示没有访问过结点
        G->BFSflag[i] = 0;
    }
    //创建邻接矩阵
    cout << "请输入边 edges(vi,vj) 注意！！！顶点是从0到VES-1" << endl;
    for (int i = 0; i < G->edges; i++)
    {
        cin >> vi >> vj;
        G->e[vi][vj] = 1;
        G->e[vj][vi] = 1;
    }
    return G;
}
void dfs(Graph *G, int ves)
{
    if (G->DFSflag[ves] == 1)
        return;
    stack<int> sta; //创建一个栈
    cout << ves << " ";

    G->DFSflag[ves] = 1; //已经访问过结点ves了
    sta.push(ves);       //该点入栈

    while (!sta.empty())
    {
        int nowNode;
        int i;

        nowNode = sta.top();
        for (i = 0; i < G->ves; i++)
        {
            if (G->e[nowNode][i] != 0 && G->DFSflag[i] != 1)
            {
                cout << i << " ";
                G->DFSflag[i] = 1;
                sta.push(i); //该点入栈
                break;
            }
        }
        if (i == G->ves) //data相邻的结点都访问结束了，就弹出data
        {
            sta.pop();
        }
    }
    return;
}
void bfs(Graph *G, int ves)
{
    if (G->BFSflag[ves] == 1)
        return;
    queue<int> Q;
    cout << ves << " ";
    G->BFSflag[ves] = 1;
    Q.push(ves);
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        for (int i = 0; i < G->ves; i++)
        {
            if (G->e[nowNode][i] != 0 && G->BFSflag[i] != 1)
            {
                cout << i << " ";
                Q.push(i);
                G->BFSflag[i] = 1;
            }
        }
    }
    return;
}
int main()
{
    Graph *G = new Graph;
    G = createGraph(G);
    cout << "该图从第一个顶点开始，深度优先搜索为:" << endl;
    for (int i = 0; i < G->ves; i++) //遍历整个图，可能不是连通图
        dfs(G, i);
    cout << endl;
    cout << "该图从第一个顶点开始，广度优先搜索为:" << endl;
    for (int i = 0; i < G->ves; i++) //遍历整个图，可能不是连通图
        bfs(G, i);
    cout << endl;
    delete G;
    return 0;
}