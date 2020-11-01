#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Node
{
    int val, data;
    int h;
    int bf;
    Node *left, *right;
} Node;
class AvlTree
{
private:
    Node *root;

public:
    void Init()
    {
        root = NULL;
    }
    int Height(Node *T)
    {
        if (T == NULL)
            return 0;
        return T->h;
    }
    int Bf(Node *T)
    {
        if (T->left == T->right)
            return 0;
        if (T->left == NULL)
            return -(T->right->h);
        if (T->right == NULL)
            return T->left->h;
        return (T->left->h) - (T->right->h);
    }
    Node *LL_rotate(Node *T)
    {
        Node *B = T->left;
        T->left = B->right;
        B->right = T;
        T->h = max(Height(T->left), Height(T->right)) + 1; //计算 T 树和 B 树的高度
        B->h = max(Height(B->left), Height(T->right)) + 1;
        T->bf = Bf(T); //计算 T 树和 B 树的平衡因子
        B->bf = Bf(B);
        return B; //返回子根 B
    }
    Node *RR_rotate(Node *T) //对 T 进行单向左旋平衡处理
    {
        Node *B = T->right;
        T->right = B->left;
        B->left = T;
        T->h = max(Height(T->left), Height(T->right)) + 1; //计算 T 树和 B 树的高度
        B->h = max(Height(B->left), Height(T->right)) + 1;
        T->bf = Bf(T); //计算 T 树和 B 树的平衡因子
        B->bf = Bf(B);
        return B; //返回子根 B
    }
    Node *LR_rotate(Node *T) //对 T 进行先左后右平衡处理
    {
        T->left = RR_rotate(T->left); //单向左旋平衡处理 T 的左子树
        T = LL_rotate(T);             //单向右旋平衡处理 T
        return T;                     //返回结果
    }
    Node *RL_rotate(Node *T) //对 T 进行先右后左平衡处理
    {
        T->right = LL_rotate(T->right); //单向右旋平衡处理 T 的右子树
        T = RR_rotate(T);               //单向左旋平衡处理 T
        return T;                       //返回结果
    }
    void Insert(int v, int e) //由于 root 是私有成员（private），所以不能从主函数传入
    {
        Insert(root, v, e); //将名为 v、优先级为 e 的客户插入 AVL 树
    }
    void Insert(Node *&T, int v, int e) //将名为 v、优先级为 e 的客户插入 AVL 树 T
    {
        if (T == NULL) //若指针空（树叶），则找到插入位置
        {
            T = (Node *)malloc(sizeof(Node));
            T->h = 1;
            T->bf = 0;
            T->val = v;
            T->data = e;
            T->left = T->right = NULL;
            return;
        }
        if (e < T->data)
            Insert(T->left, v, e);
        else
            Insert(T->right, v, e);
        T->h = max(Height(T->left), Height(T->right)) + 1; //计算节点高度
        T->bf = Bf(T);                                     //计算平衡因子
        if (T->bf > 1 || T->bf < -1)                       //若因插入导致不平衡，则继续相应的调整
        {
            if (T->bf > 1 && T->left->bf > 0)
                T = LL_rotate(T); //处理不平衡的 LL 情况
            if (T->bf < -1 && T->right->bf < 0)
                T = RR_rotate(T); //处理不平衡的 RR 情况
            if (T->bf > 1 && T->left->bf < 0)
                T = LR_rotate(T); //处理不平衡的 LR 情况
            if (T->bf < -1 && T->right > 0)
                T = RL_rotate(T); //处理不平衡的 RL 情况
        }
    }
    void Find(int flag)
    {
        if (root == NULL) //若 AVL 树空，则返回 0
        {
            printf("0\n");
            return;
        }
        Node *temp = root; //当前节点初始化为根
        if (flag)          //若服务最高优先级的客户，则寻找最右端的节点 temp
        {
            while (temp->right)
                temp = temp->right;
        }
        else //若服务最低优先级的客户，则寻找最左端的节点 temp
        {
            while (temp->left)
                temp = temp->left;
        }
        printf("%d\n", temp->val); //输出该节点的名字域
        Delete(root, temp->data);  //根据该节点的优先级将其从树中删除
    }
    void Delete(Node *&T, int e) //从 AVL 树 T 中删除优先级为 e 的节点
    {
        if (T == NULL)
            return; //若 T 树空，则返回
        if (e < T->data)
            Delete(T->left, e); //若优先级 e 小于当前节点，则沿左子树方向寻找
        else if (e > T->data)
            Delete(T->right, e); //若优先级 e 大于当前节点，则沿右子树方向寻找
        else                     //找到删除的节点 T
        {
            if (T->left && T->right) //若被删节点 T 有左右子树
            {
                Node *temp = T->left;
                while (temp->right)
                    temp = temp->right;
                T->val = temp->val;
                T->data = temp->data;
                Delete(T->left, temp->data); //在 T 的左子树中删除 temp
            }
            else //若 T 最多有一个孩子
            {
                Node *temp = T; //将 T 记为 temp
                if (T->left)
                    T = T->left; //将其孩子设为 T
                else if (T->right)
                    T = T->right;
                else //被删除节点 T 没有孩子
                {
                    free(T);  //释放树 T 所占内存
                    T = NULL; //AVL 树置空
                }
                if (T)
                    free(temp); //若 T 仅 1 个孩子，则释放 temp 节点所占内存
                return;
            }
        }
        T->h = max(Height(T->left), Height(T->right)) + 1; //调整 T 的树高和平衡因子
        T->bf = Bf(T);
        if (T->bf > 1 || T->bf < -1) //若删除操作导致不平衡，则分情形进行相应平衡处理
        {
            if (T->bf > 1 && T->left->bf > 0)
                T = LL_rotate(T); //对*T 进行单向右旋平衡处理
            if (T->bf < -1 && T->right->bf < 0)
                T = RR_rotate(T); //对*T 进行单向左旋平衡处理
            if (T->bf > 1 && T->left->bf < 0)
                T = LR_rotate(T); //对*T 进行先左后右平衡处理
            if (T->bf < -1 && T->right > 0)
                T = RL_rotate(T); //对*T 进行先右后左平衡处理
        }
    }
    void Free() //由于类的内存是 malloc 出来的，因此用后一定要释放
    {
        FreeNode(root); //释放 T 树所占的内存
    }
    void FreeNode(Node *T) //释放 T 树所占的内存
    {
        if (T == NULL)
            return; // 若 T 树空，则返回
        if (T->right)
            FreeNode(T->right); //若左子树非空，则递归释放左子树
        if (T->left)
            FreeNode(T->left); //若右子树非空，则递归释放右子树
        free(T);               //释放子根 T
    }
};
AvlTree T; //T 为类 AvlTree
int main() //主程序
{
    T.Init();                       //初始时 AVL 树为空
    int op;                         //服务代码
    while (~scanf("%d", &op) && op) //反复输入代码 op，直至输入 0 为止
    {
        if (op == 1) //若需加入新客户，则输入客户名 v 和优先级 e
        {
            int v, e;
            scanf("%d%d", &v, &e);
            T.Insert(v, e); //将该客户插入 AVL 树
        }
        if (op == 2) //若服务最高优先级的客户，则输出该客户的名字，并将其从 AVL 树删除
        {
            T.Find(1);
        }
        if (op == 3) //若服务最低优先级的客户，则输出该客户的名字，并将其从 AVL 树删除
        {
            T.Find(0);
        }
    }
    T.Free(); //释放 T 类的内存
    return 0;
}