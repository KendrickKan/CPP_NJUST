#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem0(a) memset(a, 0, sizeof(a))
#define memfu1(a) memset(a, -1, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define EPS 1e-10
const int MOD = 1e9 + 7;
//INT_MAX <limits>
#define PI acos(-1)
template <typename T>
void read(T &t)
{
    t = 0;
    char ch = getchar();
    int f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    do
    {
        (t *= 10) += ch - '0';
        ch = getchar();
    } while ('0' <= ch && ch <= '9');
    t *= f;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// const int maxn = 100;

// bool vis[maxn][maxn]; //访问标记
// int mapp[maxn][maxn]; //坐标范围

// bool check(int x, int y)
// {                          //边界条件和约束条件的判断
//     if (!vis[x][y] && ...) //满足条件
//         return 1;
//     else
//         return 0;
// }
// void DFS(int x, int y)
// {
//     vis[x][y] = 1; //标记该节点被访问
//     if (mapp[x][y] == G)
//     {       //出现目标态G
//         ... //做相应处理
//             return;
//     }
//     for (int i = 0; i < 4; i++)
//     {
//         if (check(x + dir[i][0], y + dir[i][1])) //按照规矩生成下一个节点
//             DFS(x + dir[i][0], y + dir[i][1]);
//     }
//     return; //没有下层搜索节点，回溯
// }
int main()
{
    FastIO;
    return 0;
}