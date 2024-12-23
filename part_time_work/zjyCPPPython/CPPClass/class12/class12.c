// 数组：静态分配、动态分配
// 链表，链表的操作（增加，删除，创建节点，遍历，释放）
// typedef
// #define
#include <stdio.h>
#include <stdlib.h>
// #include "list.h" 简化我们写代码，把一些常用的东西全部都封装好放在头文件里，下次直接调用就行
// C语言和C++都封装很多常用的东西，放在头文件里，我们只需要include这些头文件就可以了
// C++也封装好了链表，STL里面有链表，我们只需要include这个头文件就可以了 后面再讲

// 节点的结构体
struct node
{
    int data;          // 数据域
    struct node *next; // 指针域，指向下一个节点，由于下一个节点也是一个结构体，所以这里是指向结构体的指针
};

// 创建一个新的节点的函数，声明函数
struct node *create_node(int a);
void list_add_tail(struct node *head, struct node *new_node);       // 向链表的尾部添加一个新的节点
void list_add(struct node *head, struct node *new_node, int index); // 向链表的指定位置添加一个新的节点
void list_delete(struct node *head, int index);                     // 删除指定位置的节点
void list_free(struct node *head);                                  // 释放链表的内存
void list_traverse(struct node *head);                              // 遍历链表

int main()
{
    printf("第十二次课\n");
    // 定义一个头节点，由于现在还没有第一个节点，所以头节点是NULL
    struct node *head = NULL;
    // 创建一个新的节点
    // 大量重复的代码，可以封装成函数
    struct node *p1 = create_node(1); // 创建了一个新的节点，节点的数据域是1，p1是新的节点的地址，指向新的节点
    struct node *p2 = create_node(2); // 创建了一个新的节点，节点的数据域是2，p2是新的节点的地址，指向新的节点
    // head->p1->p2->NULL
    // head->p1
    head = p1; // 头节点指向第一个节点
    // p1->p2
    p1->next = p2; // 第一个节点指向第二个节点
    // p2->NULL，不用做，因为p2->next已经是NULL
    struct node *p3 = create_node(3); // 创建了一个新的节点，节点的数据域是3，p3是新的节点的地址，指向新的节点
    p2->next = p3;                    // 第二个节点指向第三个节点
    // 封装成函数，向链表的尾部添加一个新的节点
    struct node *p4 = create_node(4); // 创建了一个新的节点，节点的数据域是4，p4是新的节点的地址，指向新的节点
    list_add_tail(head, p4);          // 向链表的尾部添加一个新的节点
    // 向链表的指定位置添加一个新的节点，封装成函数，void，（head，new_node，int index）
    // 删除指定位置的节点，封装成函数，void，（head，int index） //课后作业

    // 遍历链表，封装成函数，void，（head）
    list_traverse(head); // 遍历链表

    // 链表用完了，要释放内存，释放每一个节点的内存，封装成函数，void，（head）
    list_free(head); // 释放链表的内存

    // int i;
    // for (i = 0; i < 2; i++)
    // {
    //     printf("%d\n", i);
    // }
    // printf("%d\n", i);

    return 0;
}

// 创建一个新的节点的函数，定义函数，实现函数
struct node *create_node(int a)
{
    // 给新的节点分配内存空间malloc，void *是万能指针，可以指向任何类型的数据
    struct node *p = (struct node *)malloc(sizeof(struct node));
    // 检查是否分配成功，如果等于NULL，说明分配失败，因为并没有分配内存，为空指针
    if (p == NULL)
    {
        printf("分配内存失败\n");
        return NULL; // 结束函数，直接return NULL
    }
    // 给新的节点赋值
    // p是一个结构体的指针，可以用->来访问结构体指针的成员
    p->data = a;
    p->next = NULL; // 由于不知道下一个节点是什么，所以先指向NULL
    return p;       // 返回新的节点的地址
}

void list_add_tail(struct node *head, struct node *new_node)
{
    // 有一个head指针
    // 有一个new_node指针
    // 先找到链表的尾部
    // 从头节点开始，依次访问每一个节点，直到最后一个节点
    // 从头节点开始，定义了一个p指针，指向头节点
    struct node *p = head; // 要放在for循环外面，因为for循环结束后，p指向的是最后一个节点
    for (; p->next != NULL; p = p->next)
    {
        // 什么都不做，只是让p指向下一个节点
        // 这里的目标是找到最后一个节点
    }
    // 经历完上面的循环，p指向了最后一个节点
    p->next = new_node; // 最后一个节点指向新的节点
}

void list_add(struct node *head, struct node *new_node, int index)
{
    // 有一个head指针，指向头节点
    // 有一个new_node指针，指向新的节点
    // 有一个index，指定要插入的位置
    // 从头节点开始，依次访问每一个节点，直到指定位置
    // 从头节点开始，定义了一个p指针，指向头节点
    struct node *p = head;
    // 从头节点开始，依次访问每一个节点，直到指定位置
    for (int i = 0; i < index; i++)
    {
        // 什么都不做，只是让p指向下一个节点
        // 这里的目标是找到指定位置的节点
        p = p->next;
    }
    // 经历完上面的循环，p指向了指定位置的节点

    // struct node *temp = p->next; // 保存原来的下一个节点
    // p->next = new_node;
    // new_node->next = temp;

    new_node->next = p->next; // 新的节点指向原来的下一个节点
    p->next = new_node;       // 原来的节点指向新的节点
}

void list_free(struct node *head)
{
    // 有一个head指针，指向头节点
    // 从头节点开始，依次访问每一个节点，直到最后一个节点
    // 从头节点开始，定义了一个p指针，指向头节点
    struct node *p = head;
    // 从头节点开始，依次访问每一个节点，直到最后一个节点
    while (p != NULL) // 当p不是NULL的时候，继续循环，说明当前p还是链表的节点
    {
        // 保存下一个节点的地址 !!! 一定要先保存下一个节点的地址，因为当前节点的地址要释放
        struct node *temp = p->next;
        // 释放当前节点的内存
        free(p);
        // p指向下一个节点
        p = temp;
    }
    // 释放完所有的节点后，头节点也要释放
    head = NULL;
}

void list_traverse(struct node *head)
{
    // 可以用for
    // 从头节点开始，依次访问每一个节点，直到最后一个节点
    struct node *p = head;
    for (; p != NULL; p = p->next)
    {
        printf("%d\n", p->data);
    }

    // 也可以while，课后作业
}