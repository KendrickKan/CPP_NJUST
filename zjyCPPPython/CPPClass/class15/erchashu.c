// 二叉树 对于一个父节点，左子树，右子树
struct erchashu
{
    /* data */
    int data;
    // 左子树
    struct erchashu *left;
    // 右子树
    struct erchashu *right;
};


// struct erchashu * node1 = (erchashu *)malloc(sizeof(erchashu));
// node1->data = 1;
// node1->left = NULL;
// node1->right = NULL;
// struct erchashu * node2 = (erchashu *)malloc(sizeof(erchashu));
// node2->data = 2;
// node2->left = NULL;
// node2->right = NULL;
// node1->left = node2;