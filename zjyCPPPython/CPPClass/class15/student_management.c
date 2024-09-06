#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "tool.h"

struct Student
{
    char name[20];
    int number;
    int grade;
    struct Student *next;
};

struct Student *create_Student(char name[20], int number, int grade);
void list_add_tail(struct Student *head, struct Student *new_Student, char name[20], int number, int grade);
void list_delete(struct Student *head, int number); // 删除指定位置的节点
void list_search(struct Student *head, int number);
void list_free(struct Student *head);     // 释放链表的内存
void list_traverse(struct Student *head); // 遍历链表

int main()
{
    // 定义头节点
    struct Student *head = (struct Student *)malloc(sizeof(struct Student));
    if (head == NULL)
    {
        printf("Failed to allocate memory for head.\n");
        return 1;
    }
    head->next = NULL; // 初始化头节点的 next 指针为 NUL // 分配了一个Student的内存,head就是这个内存的首地址

    printf("option 1:添加\n");
    printf("option 2:删除\n");
    printf("option 3:查找\n");
    printf("option 4:显示\n");
    printf("option 5:结束\n");
    int operation = 0; // 使用operation定义用户行为
    while (operation != 5)
    {
        scanf("%d", &operation); // 用户输入需要干什么
        if (operation == 1)
        {

            char a[20];
            int b;
            int c;

            printf("姓名\n");
            scanf("%s", &a);
            printf("学号\n");
            scanf("%d", &b);
            printf("成绩\n");
            scanf("%d", &c);

            struct Student *p1 = create_Student(a, b, c);
            if (head == NULL)
            {
                head = p1;
            }

            list_add_tail(head, p1, a, b, c);
        }

        if (operation == 2)
        {
            int b;
            printf("学号\n");
            scanf("%d", &b);

            list_delete(head, b);
        }

        if (operation == 3)
        {
            int b;
            printf("学号\n");
            scanf("%d", &b);

            list_search(head, b);
        }

        if (operation == 4)
        {
            list_traverse(head);
        }

        // if(operation == 5)
        // {
        //     FILE *fp = fopen("students.txt", "w");
        //     if (fp == NULL)
        //     {
        //         printf("文件打开失败\n");
        //         return 0;
        //     }
        //     else
        //     {
        //         printf("文件打开成功\n");

        //         struct Student *p = head;
        //         for (; p != NULL; p = p->next)
        //         {
        //             printf("number = %d\n, name = %s\n, grade = %d\n", p->number, p->name, p->grade);

        //             char *str1 = p->number;
        //             char *str2 = p->name;
        //             char *str3 = p->grade;
        //             int ret1 = fputs(str1, fp);
        //             int ret2 = fputs(str2, fp);
        //             int ret3 = fputs(str3, fp);
        //             if (ret1 == EOF || ret2 == EOF || ret3 == EOF)
        //             {
        //                 printf("写入文件失败\n");
        //             }
        //             else
        //             {
        //                 printf("写入文件成功\n");
        //             }
        //         }
        //             fclose(fp); // 关闭文件
        //     }

        //     list_free(head);
        //     break;
        // }
    }

    return 0;
}

// 创建一个新的节点的函数，定义函数，实现函数
struct Student *create_Student(char name[20], int number, int grade)
{
    struct Student *p = (struct Student *)malloc(sizeof(struct Student));
    if (p == NULL)
    {
        printf("分配内存失败\n");
        return NULL;
    }
    strcpy(p->name, name);
    p->number = number;
    p->grade = grade;
    p->next = NULL;
    return p;
}

void list_add_tail(struct Student *head, struct Student *new_Student, char name[20], int number, int grade)
{

    struct Student *p = head;

    // do
    // {
    //     p = p->next;
    // } while (p->next != NULL);
    for (; p->next != NULL; p = p->next)
    {
        // 什么都不做，只是让p指向下一个节点
        // 这里的目标是找到最后一个节点
    }

    p->next = new_Student; // 最后一个节点指向新的节点

    strcpy(new_Student->name, name);
    new_Student->number = number;
    new_Student->grade = grade;

    new_Student->next = NULL; // 由于不知道下一个节点是什么，所以先指向NULL
}

void list_delete(struct Student *head, int number)
{
    struct Student *p = head;

    for (; p != NULL; p = p->next)
    {

        struct Student *listp = p->next;
        if (listp->number == number)
        {
            p->next = listp->next;
            free(listp);
        }
    }
}

void list_search(struct Student *head, int number)
{
    struct Student *p = head;

    for (; p != NULL; p = p->next)
    {

        struct Student *listp = p->next;
        if (listp->number == number)
        {
            printf("number = %d\n, name = %s\n, grade = %d\n", listp->number, listp->name, listp->grade);
        }
    }
}

void list_free(struct Student *head)
{

    struct Student *p = head;

    while (p != NULL)
    {
        struct Student *temp = p->next;
        free(p);

        p = temp;
    }
    head = NULL;
}

void list_traverse(struct Student *head)
{
    struct Student *p = head;
    for (; p != NULL; p = p->next)
    {
        printf("number = %d\n, name = %s\n, grade = %d\n", p->number, p->name, p->grade);
    }
}