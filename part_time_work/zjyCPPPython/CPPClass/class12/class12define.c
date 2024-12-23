// typedef
// #define
#include <stdio.h>
// #define 定义一个宏,宏是一个标识符
// #define 宏名 宏体
#define PI 3.1415926
// 宏名是PI,宏体是3.1415926
// 宏名是一个标识符,宏体是一个表达式

// typedef 定义一个新的类型
// typedef 类型名 新类型名
typedef int INT;

typedef struct node
{
    int data;          // 数据域
    struct node *next; // 指针域，指向下一个节点，由于下一个节点也是一个结构体，所以这里是指向结构体的指针
} NODE;

// typedef struct node NODE;
typedef long long LL;

// typedef的好处，可以简化代码，提高代码的可读性

// 宏定义和typedef的区别
// 宏定义是在预处理阶段，是一个简单的文本替换,#define 宏名 宏体
// typedef是在编译阶段，是定义一个新的类型，typedef int INT;

// #include <xXXXXX> 用尖括号表示是系统的头文件head文件
// #include "xXXXXX" 用双引号表示是用户自定义的头文件
// 为什么要有头文件？
// 1.头文件是用来声明函数的，函数的声明和函数的实现是分开的
// 2.头文件是用来声明结构体的，结构体的声明和结构体的定义是分开的
// 3.头文件是用来声明宏定义的，宏定义是在预处理阶段，是一个简单的文本替换
// 4.头文件是用来声明typedef的，typedef是定义一个新的类型
// 5.头文件是用来声明全局变量的，全局变量的声明和定义是分开的
// 6.头文件是用来声明枚举的，枚举的声明和定义是分开的
// 。。。
// 为什么要有头文件？ 为了提高代码的可读性，提高代码的可维护性，提高代码的可扩展性
// printf scanf malloc free 都是常用的函数，这些函数的声明在哪里？在stdio.h stdlib.h头文件里面
// 编译器已经把这些函数的声明写好了，我们只需要include这些头文件就可以了

int main()
{
    printf("第十二次课\n");
    INT a = 10;
    NODE *head = NULL;
    LL b = 1000000000000000000;
    return 0;
}