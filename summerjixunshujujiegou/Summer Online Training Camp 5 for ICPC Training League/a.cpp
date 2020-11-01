#include <iostream>
using namespace std;
struct bintreenode
{
    int data;
    bintreenode *leftchild, *rightchild;
};
typedef bintreenode *Btree;
void insert(Btree &T, int x)
{
    if (T == NULL)
    {
        T = new bintreenode;
        T->data = x;
        T->leftchild = T->rightchild = NULL;
    }
    else if (x < T->data)
        insert(T->leftchild, x);
    else
        insert(T->rightchild, x);
}
void preprint(Btree T, bool flag)
{
    if (T == NULL)
        return;
    else
    {
        if (!flag)
            cout << ' ';
        cout << T->data;
        preprint(T->leftchild, 0);
        preprint(T->rightchild, 0);
    }
}
int main()
{
    int n, data;
    Btree T;
    while (cin >> n)
    {
        T = NULL;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            insert(T, data);
        }
        preprint(T, 1);
        cout << endl;
    }

    return 0;
}