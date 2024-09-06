#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[501][501] = {0}; // ��ͼ
int n, m, a, b;
int infected = 0; // �Ѹ�Ⱦ������
int num = 0;      // �Ż�ʱ�临�Ӷ�
int xd[4] = {0, -1, 0, 1};
int yd[4] = {-1, 0, 1, 0};
vector<pair<int, int>> in;       // �Ѹ�Ⱦ����
vector<pair<int, int>> suzerain; // ��������
vector<int> infecttime;          // ��Ⱦ�������У����ڼ�¼������Ⱦʱ�䣩
int Time = 0;

int check(int x, int y)
{
    if (x > 0 && x <= n && y > 0 && y <= m && !graph[x][y])
    {
        return 1;
    }
    return 0;
}

void BFS()
{
    Time++;                // �ִ�
    int Isize = in.size(); // ���и�Ⱦ��������һȦ
    for (int i = num; i < Isize; i++, num++)
    {
        for (int j = 0; j < 4; j++) // �ĸ�����
        {
            int xx = in[i].first + xd[j];
            int yy = in[i].second + yd[j];
            if (check(xx, yy))
            {
                in.push_back(make_pair(xx, yy));
                graph[xx][yy] = 1;
            }
        }
    }
    for (int k = 0; k < b; k++) // �����Ƿ�����
    {
        if (infecttime[k] == -1 && graph[suzerain[k].first][suzerain[k].second] == 1)
        {
            infecttime[k] = Time;
            infected++;
        }
    }
}

int main()
{
    cin >> n >> m >> a >> b;
    int x, y;
    infecttime.resize(b, -1);
    for (int i = 0; i < a; i++)
    {
        cin >> x >> y;
        graph[x][y] = 1;
        in.push_back(make_pair(x, y));
    }
    for (int i = 0; i < b; i++)
    {
        cin >> x >> y;
        suzerain.push_back(make_pair(x, y));
        if (graph[x][y] == 1)
        {
            infected++;
            infecttime[i] = 0;
        }
    }
    while (infected < b)
    {
        BFS();
    }
    for (int i = 0; i < infecttime.size(); i++)
    {
        cout << infecttime[i] << endl;
    }
}
