#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;
struct knode
{
    int num;
    int len;
};

void init(knode *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].num = -1;
        p[i].len = 0;
    }
}

int Find(int x, knode *pn)
{
    if (pn[x].num < 0)
        return pn[x].num;
    return pn[x].num = Find(pn[x].num, pn);
}

// 合并：大的合并到小的那里
void Union(int x, int y, knode *pn, int len)
{
    int h1 = Find(x, pn);
    int h2 = Find(y, pn);
    if (h1 < h2) // 合并到小的那里
    {
        pn[h2].num = h1;
        pn[h2].len += len;
        pn[h1].num--;
    }
    else if (h1 == h2) // 同属一个等价类，则返回
    {
        return;
    }
    else
    {
        pn[h1].num = h2;
        pn[h1].len += len;
        pn[h2].num--;
    }
}
const int N = 10000;
int main()
{
    knode *parent = new knode[N];
    init(parent, N);

    int m;
    cin >> m;
    string str1, str2;
    map<string, int> ms;
    map<string, int>::iterator msi;
    vector<string> mv(m);
    int i = 0, j = 0;
    while (i < 2 * m)
    {
        cin >> str1;
        if (ms.count(str1) == 0)
        {
            ms.insert(pair<string, int>(str1, j));
            mv.insert(mv.begin() + j, str1);
            j++;
        }
        i++;
        cin >> str2;
        if (ms.count(str2) == 0)
        {
            ms.insert(pair<string, int>(str2, j));
            mv.insert(mv.begin() + j, str2);
            j++;
        }
        i++;
        int len;
        cin >> len;
        msi = ms.find(str1);
        int x = msi->second;
        msi = ms.find(str2);
        int y = msi->second;
        Union(x, y, parent, len);
    }
    int maxlength = 0;
    for (int i = 0; i < m; i++)
    {
        if (parent[i].len > maxlength)
        {
            maxlength = parent[i].len;
        }
    }
    cout << maxlength << endl;

    delete[] parent;
    return 0;
}