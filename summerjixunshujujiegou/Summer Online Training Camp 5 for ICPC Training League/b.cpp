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
void find(Btree T, int x)
{
    if (x > T->data)
    {
        cout << 'W';
        find(T->rightchild, x);
    }
    else if (x < T->data)
    {
        cout << 'E';
        find(T->leftchild, x);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Btree T;
        T = NULL;
        int data;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            insert(T, data);
        }
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            find(T, data);
            cout << endl;
        }
    }

    return 0;
}