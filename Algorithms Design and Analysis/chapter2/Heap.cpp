/*
 * @Author: KendrickKan 
 * @Date: 2021-03-18 23:04:42 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-03-20 21:30:49
 * @about：Heap
 */
#include <bits/stdc++.h>
using namespace std;
const int maxnum = 1000;
int heap[maxnum];
int n;
void Sift_up(int i)
{
    bool done = false;
    if (i == 1)
        return;
    while (!done && i != 1)
    {
        int tempfu = (int)floor(i * 1.0 / 2); //父节点
        if (heap[i] > heap[tempfu])
        {
            int temp = heap[i];
            heap[i] = heap[tempfu];
            heap[tempfu] = temp;
        }
        else
            done = true;
        i = tempfu;
    }
}
void Sift_down(int i)
{
    bool down = false;
    if (2 * i > n)
        return;
    while (2 * i <= n && !down)
    {
        i = 2 * i;
        if (i + 1 <= n && heap[i + 1] > heap[i])
            i = i + 1;
        int tempson = (int)floor(i * 1.0 / 2);
        if (heap[tempson] < heap[i])
        {
            int temp = heap[tempson];
            heap[tempson] = heap[i];
            heap[i] = temp;
        }
        else
            down = true;
    }
}
void Heap_Insert(int x)
{
    n += 1;
    heap[n] = x;
    Sift_up(n);
    return;
}
void Heap_Delete(int i)
{
    int x = heap[i];
    int y = heap[n];
    n -= 1;
    if (i == n + 1)
        return;
    heap[i] = y;
    if (heap[i] >= x)
        Sift_up(i);
    else
        Sift_down(i);
    return;
}
int Delete_max()
{
    int x = heap[1];
    Heap_Delete(1);
    return x;
}
void Make_Heap()
{
    for (int i = (int)floor(n * 1.0 / 2); i >= 1; i--)
        Sift_down(i);
    return;
}
int main()
{
    n = 10;
    for (int i = 1; i <= n; i++)
        heap[i] = i;
    Make_Heap();
    for (int i = 1; i <= n; i++)
        cout << heap[i] << " ";
    Heap_Delete(5);
    for (int i = 1; i <= n; i++)
        cout << heap[i] << " ";
    return 0;
}