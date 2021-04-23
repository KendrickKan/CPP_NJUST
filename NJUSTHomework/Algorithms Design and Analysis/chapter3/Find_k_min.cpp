/*
 * @Author: KendrickKan 
 * @Date: 2021-03-24 14:22:56 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-03-24 15:00:47
 * @about：Find_k_min
 */
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
const int MAXN = 5000005;
int n, k;
vector<int> tvec;
bool cmp(int a, int b)
{
    return a < b;
}
void select(vector<int> vec, int k)
{
    int p = vec.size();
    if (p < 44)
    {
        sort(vec.begin(), vec.end(), cmp);
        cout << vec[k - 1];
        return;
    }
    int num = p / 5;
    vector<int> M;
    for (int i = 0; i < num; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 5; j++)
        {
            temp.push_back(vec[i * 5 + j]);
        }
        sort(temp.begin(), temp.end(), cmp);
        M.push_back(temp[2]);
    }
    sort(M.begin(), M.end(), cmp);
    int mm = M[(int)floor(num * 1.0 / 2)];
    vector<int> A1;
    vector<int> A2;
    vector<int> A3;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < mm)
            A1.push_back(vec[i]);
        else if (vec[i] == mm)
            A2.push_back(vec[i]);
        else
            A3.push_back(vec[i]);
    }
    if (A1.size() >= k)
        select(A1, k);
    else if (A1.size() + A2.size() >= k)
    {
        cout << mm;
        return;
    }
    else
        select(A3, k - (A1.size() + A2.size()));
}
int main()
{
    FastIO;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tvec.push_back(x);
    }
    select(tvec, k);
    return 0;
}