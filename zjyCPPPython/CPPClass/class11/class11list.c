// 链表
#include <stdio.h>
#include <stdlib.h>

// 用结构体定义一个链表的节点/元素
struct Node
{
    int data;          // 数据域
    struct Node *next; // 指针域,指向下一个节点,节点的地址,节点的指针
};

int main()
{
    // 一个链表是由一系列的节点组成,每个节点包含两部分,数据和指向下一个节点的指针
    // 链表的头节点是第一个节点的地址 head = &node1
    struct Node node1 = {1, NULL}; // 第一个节点
    struct Node node2 = {2, NULL}; // 第二个节点
    struct Node node3 = {3, NULL}; // 第三个节点
    // 定义一个头节点
    struct Node *head = &node1; // 链表的头节点是第一个节点的地址
    // 连接链表
    // 连接第一个节点和第二个节点
    node1.next = &node2; // 第一个节点的指针域指向第二个节点
    // 连接第二个节点和第三个节点
    node2.next = &node3; // 第二个节点的指针域指向第三个节点
    // 第三个节点是最后一个节点,最后一个节点的指针域是NULL
    // 通过上述的操作,我们就得到了一个链表，head->node1->node2->node3->NULL
    // 遍历链表
    // 从头节点开始,依次访问每一个节点,直到最后一个节点
    // for(int i =0 ; i < lentgh; i++) 数组是用 i 下标
    // i++ ===== i = i + 1
    // 初始 struct Node *p = head 从头节点开始，定义了一个p指针，指向头节点
    // 结束条件 p != NULL 当p不是NULL的时候，继续循环
    // 循环变量的变化 p = p->next p指向下一个节点
    // 链表是用指针去访问的
    for (struct Node *p = head; p != NULL; p = p->next)
    {
        printf("%d\n", p->data); // p->data是节点的数据域
    }
    return 0;
}