#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int minnum;
int ans;
int in[10005], post[10005];

struct Node
{
    int num;
    Node *left;
    Node *right;
};

Node *build(int l, int *i, int *p)
{
    if (l == 0)
        return NULL;
    int pos = 0;
    while (i[pos] != p[l - 1])
        pos++;
    Node *r = new Node;
    r->num = p[l - 1];
    r->left = build(pos, i, p);
    r->right = build(l - pos - 1, i + pos + 1, p + pos);
    return r;
}

void dfs(Node *r, int n)
{
    if (r->left == NULL && r->right == NULL)
    {
        if (r->num + n <= minnum)
        {
            minnum = r->num + n;
            ans = r->num;
        }
        return;
    }
    if (r->left != NULL)
        dfs(r->left, r->num + n);
    if (r->right != NULL)
        dfs(r->right, r->num + n);
}

int main()
{
    while (scanf("%d", &in[0]) != EOF)
    {
        int len = 1;
        while (getchar() != '\n')
            cin >> in[len++];
        for (int i = 0; i < len; i++)
            cin >> post[i];
        minnum = 99998;
        Node *root = build(len, in, post);
        dfs(root, 0);
        cout << ans << endl;
    }
    return 0;
}