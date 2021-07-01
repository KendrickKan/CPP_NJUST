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
    cout << "请输入数组的元素个数>>";
    cin >> n;
    cout << endl
         << "请依次输入数组的元素>>" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    cout << "使用分治求得数组的最大值为：" << findmax(vec, 0, vec.size() - 1) << endl;
    cout << "使用分治求得数组的最小值为：" << findmin(vec, 0, vec.size() - 1) << endl;
    return 0;
}