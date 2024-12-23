// 指针
// 数组的指针
// 指针数组
// 动态分配内存
// 指针的指针

// 链表:链表是一种数据结构,链表是由一系列的节点组成,每个节点包含两部分,数据和指向下一个节点的指针
#include <stdio.h>
#include <stdlib.h>

// 链表{值,指向下一个节点的指针}
struct Student // 定义了一个链表元素的结构体
{
    int age;
    char name[20];
    struct Student *next; // 指向下一个节点的指针
};

// 数组[{10,zhangsan},{20,lisi},{30,wangwu}]
// 链表:head -> 10 zhangsan -> 20 lisi -> 30 wangwu -> NULL
// 链表和数组的区别:数组是连续存储的,链表是不连续存储的,数组不需要用指针指向下一个元素,链表需要用指针指向下一个元素

int main()
{
    printf("第10次课\n");
    // 数组的指针=数组的首地址=数组的名字=第一个元素的地址=&a[0]=a
    int a[5] = {1, 2, 3, 4, 5}; // 整数数组：数组里面存的是整数 type name[size];
    int *p = a;                 // p指向a数组的第一个元素
    // 指针数组:数组里面存的是指针 type *name[size];
    // int *b[5] = {&a[0], &a[1], &a[2], &a[3], &a[4]}; // 整数指针数组：数组里面存的是整数指针
    int *b[5];
    for (int i = 0; i < 5; i++)
    {
        b[i] = &a[i];
    }
    // 通过b数组的指针，可以访问a数组的元素
    // 输出3
    printf("%d\n", a[2]);
    printf("%d\n", *b[2]);
    // 指针的++ --操作 如果直接是+ -
    printf("%d\n", *(a + 2));
    // 指针的指针
    printf("指针的指针\n");
    printf("整数指针的大小%d\n", sizeof(int *)); // 8
    // type *指针变量，&是取地址符，*是取值符
    // 理清 指针变量,地址,取值,取地址的关系
    int x = 10;   // 整数
    int *p1 = &x; // 整数指针：存的是整数的地址，p1存的是x的地址，p1指向x
    // 指针的指针
    int **p2 = &p1; // 整数指针的指针：存的是整数指针的地址，p2存的是p1的地址，p2指向p1
    printf("x = %d\n", x);
    printf("*p1 = %d\n", *p1);
    printf("**p2 = %d\n", **p2);
    // 指针是直接表示地址的,可以直接操控内存
    // c语言的优秀的地方,可以直接操控内存,但是也是c语言的危险的地方
    // 是用指针的时候,一定要非常小心,一定要非常小心,一定要非常小心
    // 动态内存分配
    int arr[10]; // 静态内存分配,在编译的时候就分配好了内存,指定了内存的大小,40B
    // 编译完之后,在程序执行exe文件的时候输入n的值,在运行的时候分配内存,4nB
    // malloc函数,在程序运行的时候分配内存,在程序运行的时候 [分配内存],在stdlib.h头文件里面
    // malloc(size); 返回值是void * ,void *是万能指针,可以指向任何类型的数据
    // 定义一个长度为n的整数数组
    int n;
    printf("请输入数组的长度\n");
    scanf("%d", &n);
    int *arrp = (int *)malloc(n * sizeof(int)); // 分配了n个整数的内存,arrp就是这个内存的首地址,数组的指针
    // 注意安全的地方:1.分配内存的时候,最好用sizeof(int)这种方式,不要用4这种方式
    // 2.由于返回值是一个void *,所以需要强制类型转换(int *)
    // 强制类型转换的时候,最好加上括号,因为强制类型转换的优先级是最高的,在最前面加个括号,括号里填想要转换成什么类型
    // arrp就是一个存了10个元素的整数数组
    // 4.分配内存的时候,一定要检查是否分配成功,如果分配失败,返回的是NULL 空指针
    if (arrp == NULL)
    {
        printf("分配内存失败\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        arrp[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arrp[i]);
    }
    // 3.后面不需要使用的时候,一定要释放内存
    // 前面分配好了内存,后面一定要释放内存
    // free函数,在stdlib.h头文件里面 free(arrp);释放arrp指向的内存
    free(arrp);
    // 释放内存之后,arrp指向的内存就没有了,不能再使用了
    // 5.释放内存之后,一定要把指针赋值为NULL,防止野指针
    arrp = NULL;
    // 链表:链表是一种数据结构,链表是由一系列的节点组成,每个节点包含两部分,数据和指向下一个节点的指针
    printf("链表\n");
    // 定义链表
    // 定义头节点
    struct Student *head = (struct Student *)malloc(sizeof(struct Student)); // 分配了一个Student的内存,head就是这个内存的首地址
    struct Student stu1 = {10, "zhangsan", NULL};                            // 定义了一个Student类型的变量stu1
    struct Student stu2 = {20, "lisi", NULL};                                // 定义了一个Student类型的变量stu2
    struct Student stu3 = {30, "wangwu", NULL};                              // 定义了一个Student类型的变量stu3
    // head -> stu1 -> stu2 -> stu3 -> NULL
    // stu1.age 访问结构体的元素通过.来访问
    // 访问结构体指针的元素,通过->来访问
    head->next = &stu1;
    stu1.next = &stu2;
    stu2.next = &stu3;
    // 遍历链表
    struct Student *listp = head->next; // listp指向head的下一个节点
    for (; listp != NULL; listp = listp->next)
    {
        printf("age = %d, name = %s\n", listp->age, listp->name);
    }
}