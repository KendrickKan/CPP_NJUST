#include <stdio.h>
struct ListNode
{
    int data;
    struct ListNode *next;
};

// 边画图边模拟代码执行过程
struct ListNode *removeElements(struct ListNode *head, int val)
{
    // 第一步：定义一个虚拟头节点，指向head,这样可以避免删除头节点的特殊情况
    struct ListNode *temphead = (struct ListNode *)malloc(sizeof(struct ListNode));
    temphead->next = head;
    // 第二步：定义一个指针，指向虚拟头节点
    struct ListNode *p = temphead;
    // 第二步：开始遍历
    while (p->next != NULL)
    {
        // 定义一个指针，指向下一个节点
        struct ListNode *q = p->next;
        if (/* condition */) // q->data == val
        {
            p->next = q->next; // 删除 q
            /* code */ // 删除 q
        }
        else{
            // 什么都不做 p指向下一个节点
        }
    }
    // 第三步：返回head
    return temphead->next;
}