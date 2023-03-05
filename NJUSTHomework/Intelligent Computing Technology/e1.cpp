#include <bits/stdc++.h>
using namespace std;
struct node
{
    double G = 0, F = 0, H = 0;
    int x, y;
    bool is_begin = false;
    bool is_end = false;
    bool is_obstacle = false;
    int parentx = 0;
    int parenty = 0;
    bool is_road = false;
};
// 打印地图
void print_map(vector<vector<node>> node_map)
{
    for (int i = 0; i < node_map.size(); i++)
    {
        for (int j = 0; j < node_map[i].size(); j++)
        {
            if (node_map[i][j].is_road)
            {
                cout << "R ";
                continue;
            }
            if (node_map[i][j].is_begin)
            {
                cout << "B ";
            }
            else if (node_map[i][j].is_end)
            {
                cout << "E ";
            }
            else if (node_map[i][j].is_obstacle)
            {
                cout << "X ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
// 打印地图路径
void print_path(vector<vector<node>> node_map, node end)
{
    node current = end;
    while (!current.is_begin)
    {
        if (current.is_end)
        {
            current = node_map[current.parentx][current.parenty];
            continue;
        }
        node_map[current.x][current.y].is_road = true;
        current = node_map[current.parentx][current.parenty];
    }
    print_map(node_map);
}
// 计算H值
double calc_H(node current, node end)
{
    return abs(current.x - end.x) + abs(current.y - end.y);
}
// 计算G值
double calc_G(node current, node parent)
{
    if (current.x == parent.x || current.y == parent.y)
    {
        return parent.G + 1;
    }
    else
    {
        return parent.G + sqrt(2);
    }
}
// 计算F值
double calc_F(node current)
{
    return current.G + current.H;
}
// 判断是否在open_list中
bool is_in_open_list(vector<node> open_list, node current)
{
    for (int i = 0; i < open_list.size(); i++)
    {
        if (open_list[i].x == current.x && open_list[i].y == current.y)
        {
            return true;
        }
    }
    return false;
}
// 判断是否在close_list中
bool is_in_close_list(vector<node> close_list, node current)
{
    for (int i = 0; i < close_list.size(); i++)
    {
        if (close_list[i].x == current.x && close_list[i].y == current.y)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int N;
    cin >> N;
    vector<vector<node>> node_map;
    for (int i = 0; i < N; i++)
    {
        node_map.push_back(vector<node>());
        for (int j = 0; j < N; j++)
        {
            node temp;
            temp.x = i;
            temp.y = j;
            node_map[i].push_back(temp);
        }
    }
    // 随机放置障碍物，左上角和右下角不能为障碍物
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 左上角和右下角不能为障碍物
            if (i == 0 && j == 0)
            {
                node_map[i][j].is_begin = true;
                continue;
            }
            if (i == N - 1 && j == N - 1)
            {
                node_map[i][j].is_end = true;
                continue;
            }
            // 随机放置障碍物
            if (rand() % 10 == 0)
            {
                node_map[i][j].is_obstacle = true;
            }
        }
    }
    print_map(node_map);
    node begin = node_map[0][0];
    node end = node_map[N - 1][N - 1];
    // 初始化open_list和close_list
    vector<node> open_list;
    vector<node> close_list;
    open_list.push_back(begin);
    // 开始搜索
    while (open_list.size() > 0)
    {
        // 从open_list中找到F值最小的节点
        node current = open_list[0];
        for (int i = 0; i < open_list.size(); i++)
        {
            if (open_list[i].F < current.F)
            {
                current = open_list[i];
            }
        }
        // 将当前节点从open_list中移除
        for (int i = 0; i < open_list.size(); i++)
        {
            if (open_list[i].x == current.x && open_list[i].y == current.y)
            {
                open_list.erase(open_list.begin() + i);
                break;
            }
        }
        // 将当前节点加入close_list
        close_list.push_back(current);
        // 判断是否到达终点
        if (current.x == end.x && current.y == end.y)
        {
            cout << "Arrive" << endl;
            cout << "到达终点" << endl;
            break;
        }
        // 找到当前节点的相邻节点
        vector<node> neighbor_nodes;
        // 上
        if (current.x - 1 >= 0)
        {
            neighbor_nodes.push_back(node_map[current.x - 1][current.y]);
        }
        // 下
        if (current.x + 1 < N)
        {
            neighbor_nodes.push_back(node_map[current.x + 1][current.y]);
        }
        // 左
        if (current.y - 1 >= 0)
        {
            neighbor_nodes.push_back(node_map[current.x][current.y - 1]);
        }
        // 右
        if (current.y + 1 < N)
        {
            neighbor_nodes.push_back(node_map[current.x][current.y + 1]);
        }
        // 左上
        if (current.x - 1 >= 0 && current.y - 1 >= 0)
        {
            neighbor_nodes.push_back(node_map[current.x - 1][current.y - 1]);
        }
        // 右上
        if (current.x - 1 >= 0 && current.y + 1 < N)
        {
            neighbor_nodes.push_back(node_map[current.x - 1][current.y + 1]);
        }
        // 左下
        if (current.x + 1 < N && current.y - 1 >= 0)
        {
            neighbor_nodes.push_back(node_map[current.x + 1][current.y - 1]);
        }
        // 右下
        if (current.x + 1 < N && current.y + 1 < N)
        {
            neighbor_nodes.push_back(node_map[current.x + 1][current.y + 1]);
        }
        // 遍历相邻节点
        for (int i = 0; i < neighbor_nodes.size(); i++)
        {
            // 如果是障碍物或者在close_list中，跳过
            if (neighbor_nodes[i].is_obstacle || is_in_close_list(close_list, neighbor_nodes[i]))
            {
                continue;
            }
            //如果是斜着走的，判断是否有障碍物
            if (neighbor_nodes[i].x != current.x && neighbor_nodes[i].y != current.y)
            {
                if (node_map[current.x][neighbor_nodes[i].y].is_obstacle && node_map[neighbor_nodes[i].x][current.y].is_obstacle)
                {
                    continue;
                }
            }
            // 如果不在open_list中，计算G、H、F值，并加入open_list
            if (!is_in_open_list(open_list, neighbor_nodes[i]))
            {
                neighbor_nodes[i].G = calc_G(current, neighbor_nodes[i]);
                neighbor_nodes[i].H = calc_H(neighbor_nodes[i], end);
                neighbor_nodes[i].F = calc_F(neighbor_nodes[i]);
                neighbor_nodes[i].parentx = current.x;
                neighbor_nodes[i].parenty = current.y;
                open_list.push_back(neighbor_nodes[i]);
            }
            // 如果已经在open_list中，判断是否需要更新G值
            else
            {
                if (calc_G(current, neighbor_nodes[i]) < neighbor_nodes[i].G)
                {
                    neighbor_nodes[i].G = calc_G(current, neighbor_nodes[i]);
                    neighbor_nodes[i].F = calc_F(neighbor_nodes[i]);
                    neighbor_nodes[i].parentx = current.x;
                    neighbor_nodes[i].parenty = current.y;
                }
            }
        }
        // 将neighbor_nodes中的节点更新node_map
        for (int i = 0; i < neighbor_nodes.size(); i++)
        {
            node_map[neighbor_nodes[i].x][neighbor_nodes[i].y] = neighbor_nodes[i];
        }
        // 找到open_list中F值最小的节点
        node min_F_node = open_list[0];
        for (int i = 0; i < open_list.size(); i++)
        {
            if (open_list[i].F < min_F_node.F)
            {
                min_F_node = open_list[i];
            }
        }
        // 将F值最小的节点设为当前节点
        current = min_F_node;
        end = node_map[end.x][end.y];//更新终点
        // 如果当前节点是终点，结束搜索
        if (current.x == end.x && current.y == end.y)
        {
            cout << "Arrive" << endl;
            cout << "到达终点" << endl;
            break;
        }
    }
    // 打印路径a
    print_path(node_map, end);
    return 0;
}