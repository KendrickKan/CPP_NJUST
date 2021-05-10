#include <bits/stdc++.h>
using namespace std;
struct node
{
    string data = "";
    node *leftChild;
    node *rightChild;
};
void PreOrderTraversal(node *T) //先序遍历
{
    cout << "PreOrderTraversal先序遍历" << endl;
    if (T == NULL)
    {
        cout << "该二叉树为空" << endl;
        return;
    }
    stack<node *> sta; //栈
    sta.push(T);
    while (!sta.empty())
    {
        node *topNode = sta.top();
        sta.pop();
        cout << topNode->data << " ";
        //先右孩子入栈，再左孩子入栈
        if (topNode->rightChild != NULL)
            sta.push(topNode->rightChild);
        if (topNode->leftChild != NULL)
            sta.push(topNode->leftChild);
    }
    cout << endl;
    return;
}
void InOrderTraversal(node *T) //中序遍历
{
    cout << "InOrderTraversal中序遍历" << endl;
    if (T == NULL)
    {
        cout << "该二叉树为空" << endl;
        return;
    }
    stack<node *> sta; //栈
    //sta.push(T);
    node *cur = T;
    while (!sta.empty() || cur != NULL)
    {
        while (cur != NULL)
        {
            sta.push(cur);
            cur = cur->leftChild; //一直向左，左孩子入栈
        }
        if (!sta.empty())
        {
            cur = sta.top();
            sta.pop();
            cout << cur->data << " ";
            cur = cur->rightChild;
        }
    }
    cout << endl;
    return;
}
void PostOrderTraversal(node *T) //后序遍历
{
    cout << "PostOrderTraversal后序遍历" << endl;
    if (T == NULL)
    {
        cout << "该二叉树为空" << endl;
        return;
    }
    stack<node *> sta; //栈
    node *cur = T;
    node *pre = NULL;
    while (cur != NULL || !sta.empty())
    {
        while (cur != NULL)
        {
            sta.push(cur);
            cur = cur->leftChild;
        }
        if (sta.top()->rightChild == NULL || sta.top()->rightChild == pre)
        {
            cout << sta.top()->data << " ";
            pre = sta.top();
            sta.pop();
        }
        else
            cur = sta.top()->rightChild;
    }
    cout << endl;
    return;
}
int main()
{
    //给一组验证过的数据
    //a b c d f g i NULL NULL e NULL NULL h END
    //先序 a b d f e c g h i
    //中序 d b e f a g h c i
    //后序 d e f b h g i c a
    cout << "该程序按照层序生成二叉树" << endl;
    cout << "若你想该节点为空请严格输入“NULL”" << endl;
    cout << "若你想结束输入请严格输入“END”" << endl;
    node *T = NULL;
    string cData;
    queue<node *> Q;
    cin >> cData;
    if (cData != "END" && cData != "NULL")
    {
        node *tempNode = new node;
        tempNode->data = cData;
        tempNode->leftChild = NULL;
        tempNode->rightChild = NULL;
        T = tempNode;
        Q.push(tempNode);
    }
    while (!Q.empty())
    {
        node *temp = Q.front();
        Q.pop();
        cin >> cData;
        if (cData == "END")
            break;
        if (cData == "NULL")
            temp->leftChild = NULL;
        else
        {
            node *tempNode = new node;
            tempNode->data = cData;
            tempNode->leftChild = NULL;
            tempNode->rightChild = NULL;
            temp->leftChild = tempNode;
            Q.push(tempNode);
        }
        cin >> cData;
        if (cData == "END")
            break;
        if (cData == "NULL")
            temp->rightChild = NULL;
        else
        {
            node *tempNode = new node;
            tempNode->data = cData;
            tempNode->leftChild = NULL;
            tempNode->rightChild = NULL;
            temp->rightChild = tempNode;
            Q.push(tempNode);
        }
    }
    cout << endl;
    cout << "该二叉树的先序遍历为" << endl;
    PreOrderTraversal(T);
    cout << "该二叉树的中序遍历为" << endl;
    InOrderTraversal(T);
    cout << "该二叉树的后序遍历为" << endl;
    PostOrderTraversal(T);
    return 0;
}