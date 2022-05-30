#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int findmax(vector<int> vec, int i, int j)
{
    int mid = (i + j) / 2;
    if (i == j)
        return vec[i];
    else
    {
        return max(findmax(vec, i, mid), findmax(vec, mid + 1, j));
    }
}
int findmin(vector<int> vec, int i, int j)
{
    int mid = (i + j) / 2;
    if (i == j)
        return vec[i];
    else
    {
        return min(findmin(vec, i, mid), findmin(vec, mid + 1, j));
    }
}
int main()
{
    int n;
    printf("请输入数组的元素个数>>");
    scanf("%d", &n);
    printf("\n请依次输入数组的元素>>\n");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        vec.push_back(x);
    }
    printf("使用分治求得数组的最大值为：%d\n", findmax(vec, 0, vec.size() - 1));
    printf("使用分治求得数组的最小值为：%d\n", findmin(vec, 0, vec.size() - 1));
    return 0;
}