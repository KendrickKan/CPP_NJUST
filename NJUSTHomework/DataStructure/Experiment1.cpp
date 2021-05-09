#include <bits/stdc++.h>
using namespace std;
struct node
{
    float coefficient;
    int exp;
    node *next;
};
node *add(node *a, node *b)
{
once:
    node *head = a->exp <= b->exp ? a : b; //如果a的首项的指数大于等于b那么头节点弄为a，否则为b
    node *ha = a->exp <= b->exp ? a : b;
    node *pa = ha;
    node *pb = a->exp <= b->exp ? b : a;
    while (pa != NULL && pb != NULL)
    {
        if (pa->exp < pb->exp)
        {
            ha = pa;
            pa = pa->next;
        }
        else if (pa->exp == pb->exp)
        {
            float tempCoe = pa->coefficient + pb->coefficient;
            //相加不为0
            if (tempCoe != 0)
            {
                pa->coefficient = tempCoe;
                ha = pa;
                pa = pa->next;
                pb = pb->next;
            }
            //相加为0
            else
            {
                if (head == ha)
                {

                    //如果两个多项式的第一项相加为0，那么就可能会更换head
                    node *tempdela = pa;
                    node *tempdelb = pb;
                    a->next = pa->next;
                    b->next = pb->next;
                    delete tempdela;
                    delete tempdelb;
                    goto once;//重新返回入口
                    // if (pa->next != NULL && pb->next != NULL)
                    // {
                    //     head = pa->next->exp <= pb->next->exp ? pa->next : pb->next;
                    //     node *tempa = pa->next->exp <= pb->next->exp ? pa->next : pb->next;
                    //     node *tempb = pa->next->exp <= pb->next->exp ? pb->next : pa->next;
                    //     pa = tempa;
                    //     pb = tempb;
                    // }
                    // else
                    //     return pa->next == NULL ? pb->next : pa->next;
                }
                ha->next = pa->next;
                node *temp = pa;
                pa = pa->next;
                delete (temp);
                pb = pb->next;
            }
        }
        else
        {
            node *temp = new node;
            temp->coefficient = pb->coefficient;
            temp->exp = pb->exp;
            temp->next = pa;
            ha->next = temp;
            ha = ha->next;
            pb = pb->next;
        }
    }
    if (pb != NULL)
    {
        if (pa != NULL)
            pa->next = pb;
    }
    return a;
}
void print(node *p) //打印多项式
{
    // cout << p->coefficient << "x^" << p->exp;
    // if (p->next != NULL)
    //     cout << (p->next->coefficient > 0 ? "+" : "-");
    p = p->next; //哨兵
    if (p == NULL)
    {
        cout << 0 << endl;
        return;
    }
    bool flag = false;
    while (p->next != NULL)
    {
        flag = true;
        cout << abs(p->coefficient) << "x^" << p->exp << (p->next->coefficient > 0 ? "+" : "-");
        p = p->next;
    }
    if (flag)
        cout << abs(p->coefficient) << "x^" << p->exp << "." << endl;
    else
        cout << p->coefficient << "x^" << p->exp << "." << endl;
}
int main()
{
    int anum, bnum;
    cout << "请输入多项式一的项数>>>";
    cin >> anum;
    cout << endl;
    cout << "请输入多项式二的项数>>>";
    cin >> bnum;
    cout << endl;
    node *shaobinga = new node;
    shaobinga->next = NULL;
    node *shaobingb = new node;
    shaobingb->next = NULL;
    node *a = shaobinga;
    node *nowa = shaobinga;
    node *b = shaobingb;
    node *nowb = shaobingb;
    cout << "请依次输入多项式一的系数，指数，请按照指数升序排列" << endl;
    for (int i = 0; i < anum; i++)
    {
        cout << "第" << i + 1 << "项系数:";
        float tempcoe;
        cin >> tempcoe;
        cout << "第" << i + 1 << "项指数:";
        int tempexp;
        cin >> tempexp;
        cout << endl;
        node *temp = new node;
        temp->coefficient = tempcoe;
        temp->exp = tempexp;
        temp->next = NULL;
        // if (i == 0)
        // {
        //     a = temp;
        //     nowa = a;
        // }
        // else
        // {
        nowa->next = temp;
        nowa = temp;
        // }
    }
    cout << "请依次输入多项式二的系数，指数，请按照指数升序排列" << endl;
    for (int i = 0; i < bnum; i++)
    {
        cout << "第" << i + 1 << "项系数:";
        float tempcoe;
        cin >> tempcoe;
        cout << "第" << i + 1 << "项指数:";
        int tempexp;
        cin >> tempexp;
        cout << endl;
        node *temp = new node;
        temp->coefficient = tempcoe;
        temp->exp = tempexp;
        temp->next = NULL;
        // if (i == 0)
        // {
        //     b = temp;
        //     nowb = b;
        // }
        // else
        // {
        nowb->next = temp;
        nowb = temp;
        // }
    }
    cout << "多项式一为:" << endl;
    print(a);
    cout << "多项式二为:" << endl;
    print(b);
    cout << "两多项式相加为:" << endl;
    print(add(a, b));
    return 0;
}