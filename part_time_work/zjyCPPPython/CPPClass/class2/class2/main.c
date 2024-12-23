// 命令行参数
#include <stdio.h>
#define PI 3.14159

// argc 是命令行参数的个数，argv 是一个指向字符串数组的指针，其中每个字符串对应一个参数
int main(int argc, char *argv[])
{
    // printf("argc = %d\n", argc);
    printf("argv[0] = %s\n", argv[0]);
    printf("argv[1] = %s\n", argv[1]);
    printf("argv[2] = %s\n", argv[2]);
    printf("argv[3] = %s\n", argv[3]);
    printf("argv[4] = %s\n", argv[4]);

    // C语言的令牌Token ：标识符、关键字、常量、字符串、符号、分号等
    printf("Hello, World!\n");

    // C语言里面 每一句语句都要以分号结尾

    // 注释作用：提高代码的可读性，方便代码的维护 不参与编译
    // 两种注释方式：单行注释、多行注释
    // 单行注释：// 后面的内容都是注释
    // 多行注释：/* 注释内容 */
    /*
    你好
    世界
    */

    int _r = 1;
    // 标识符：变量名、函数名、常量名等
    // 标识符的命名规则：由{字母、数字、下划线}组成，{不能以数字开头}，不能是关键字
    // 可以以字母、下划线开头，{区分大小写}
    int _R = 2;

    // 关键字：C语言里面有特殊含义的单词
    // int float double char void if else for while do switch case break continue return ...

    // 空格：提高代码的可读性，方便代码的维护
    // 空格的作用：分隔标识符、关键字、常量等

    return 0;
}

// 默认如果不传参数，argc = 1，argv[0] = 程序名
// 命令行参数的作用是可以在程序运行时传递参数，这样可以使程序更加灵活

// 基本语法 令牌（Token）分号 注释 标识符 关键字 空格