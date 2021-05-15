#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int MAXEDGE = 1e9 + 7;
//邻接矩阵实现图
//该图是一个无向图
struct Edge
{
    int u, v;
    int weight;
};
struct Graph
{
    int e[MAXN][MAXN];
    int edges;
    int ves;
    int DFSflag[MAXN];
    int BFSflag[MAXN];
    vector<Edge> edge; //Kruskal用
};
int father[MAXN]; //Kruskal并查集用
bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}
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
            G->e[i][j] = MAXEDGE;
        }
        G->DFSflag[i] = 0; //标识全部置0,表示没有访问过结点
        G->BFSflag[i] = 0;
    }
    //创建邻接矩阵
    cout << "请输入边 edges(vi,vj) 以及该边长度 注意！！！顶点是从0到VES-1" << endl;
    for (int i = 0; i < G->edges; i++)
    {
        cin >> vi >> vj;
        int weight;
        cin >> weight;
        G->e[vi][vj] = weight;
        G->e[vj][vi] = weight;
        Edge tempEdge;
        tempEdge.u = vi;
        tempEdge.v = vj;
        tempEdge.weight = weight;
        G->edge.push_back(tempEdge);
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
            if (G->e[nowNode][i] < MAXEDGE && G->DFSflag[i] != 1)
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
            if (G->e[nowNode][i] < MAXEDGE && G->BFSflag[i] != 1)
            {
                cout << i << " ";
                Q.push(i);
                G->BFSflag[i] = 1;
            }
        }
    }
    return;
}
void Prim(Graph *G)
{
    int start = 0; //开始节点,默认为0
    bool visited[MAXN];
    for (int i = 0; i < G->ves; i++)
        visited[i] = false;
    visited[start] = true;
    int Min[2][MAXN]; //第一行记录目前集合中哪个点到剩余每个点距离最少，第二行记录目前集合中点到剩余每个点最少的距离
    for (int i = 0; i < G->ves; i++)
    {
        Min[0][i] = start;
        Min[1][i] = G->e[start][i];
    }
    vector<pair<int, int>> vec;
    for (int i = 0; i < G->ves; i++)
    {
        if (i == start)
            continue;
        int minedge = MAXEDGE;
        int node;
        for (int i = 0; i < G->ves; i++)
        {
            if (!visited[i] && Min[1][i] < minedge)
            {
                minedge = Min[1][i];
                node = i;
            }
        }
        vec.push_back(make_pair(Min[0][node], node)); //记录生成树
        visited[node] = true;
        for (int i = 0; i < G->ves; ++i)
        {
            if (!visited[i] && Min[1][i] > G->e[node][i])
            {
                Min[1][i] = G->e[node][i];
                Min[0][i] = node;
            }
        }
    }
    //理论来说vec.size()应该为G->ves-1
    if (vec.size() != G->ves - 1)
    {
        cout << "该图不连通" << endl;
        return;
    }
    cout << "Prim算法加入的边为:" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    return;
}
int findfather(int a) //并查集判断是否存在环
{
    while (a != father[a])
    {
        a = father[a];
    }
    return a;
}
void Kruskal(Graph *G)
{
    vector<pair<int, int>> ans;
    sort(G->edge.begin(), G->edge.end(), cmp); //将边集合排序
    for (int i = 0; i < G->ves; i++)
        father[i] = i;
    for (int i = 0; i < G->edge.size() && ans.size() < G->ves - 1; i++)
    {
        int u = G->edge[i].u;
        int v = G->edge[i].v;
        if (findfather(u) != findfather(v)) //判断父节点是否相同
        {
            ans.push_back(make_pair(u, v));
            father[findfather(u)] = father[findfather(v)]; //将两点并入一个集合中
        }
    }
    if (ans.size() != G->ves - 1)
    {
        cout << "该图不连通" << endl;
        return;
    }
    cout << "Kruskal算法加入的边为:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
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
    Prim(G);
    Kruskal(G);
    delete G;
    return 0;
}

//给出一组数据
/*
6
10
0 1 6
0 3 5
0 2 1
1 2 5
2 3 5
1 4 3
2 4 6
2 5 4
3 5 2
4 5 6
*/