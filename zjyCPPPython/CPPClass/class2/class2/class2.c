#include <stdio.h>

void mul()
{
    printf("mul\n");
}


int main()
{
    printf("Hello, World!\n");

    // 数据类型 int float double char void
    // int 整型 整数类型 2字节或者4字节

    int a = 1; //有符号整型
    // sizeof 是一个{运算符}，用来计算数据类型的大小
    printf("%d\n", sizeof(a)); // 4字节 32位 0~2^32-1
    printf("%d\n", sizeof(int)); // 4字节 32位 0~2^32-1
    // 无符号整型 unsigned int 0~2^32-1       2,147,483,647
    // 有符号整型 signed int -2^31 ~ 2^31-1 默认可以省略 signed
    // short 2字节
    // 无符号 short int = unsigned short =
    // 有符号 short int
    printf("%d\n", sizeof(short)); // 2字节 16位
    printf("%d\n", sizeof(unsigned short int)); // 4字节 32位
    // 长整型 long 4字节
    // long long 8字节
    // int, short, long, long long * signed, unsigned = 8种

    // 以一个字节为例
    // 无符号
    // 00000000 = 0
    // 11111111 = 255 = 2^8-1
    // 有符号 最高位是符号位 0表示正数 1表示负数 -2^7 ~ 2^7-1
    // 0 0000000 = 0
    // 0 1111111 = 127
    // 1 0000000 = -128
    // 1 1111111 = -1

    // char 字符型 字符类型
    // void 空类型 没有类型
    // bool 布尔类型 0 false 1 true

    // float 单精度浮点型 小数类型
    printf("%d\n", sizeof(float)); // 4字节 32位
    // double 双精度浮点型 小数类型
    printf("%d\n", sizeof(double)); // 8字节 64位
    // long double 长双精度浮点型 小数类型
    printf("%d\n", sizeof(long double)); // 16字节 128位

    // 算数运算符 + - * / %
    a = 9;
    int b = 4;
    printf("%d\n", a + b); // 3
    printf("%d\n", a - b); // -1
    printf("%d\n", a * b); // 2
    printf("%d\n", a / b); // 0
    printf("%d\n", a % b); // 1

    // 自增自减运算符 ++ -- 自己在自己的基础上加1或者减1
    a = 1;
    // printf("%d\n", a++); // 1
    // printf("%d\n", a); //2
    printf("%d\n", ++a); // 2
    printf("%d\n", a); // 2
    // 左++ 先自增 后使用
    // 右++ 先使用 后自增
    // 左-- 先自减 后使用
    // 右-- 先使用 后自减

    // 赋值运算符 = += -= *= /= %=
    a = 1;
    printf("%d\n", a); // 1
    a += 2; // a = a + 2
    printf("%d\n", a); // 3
    a -= 2; // a = a - 2
    printf("%d\n", a); // 1
    a *= 2; // a = a * 2
    printf("%d\n", a); // 2
    a /= 2; // a = a / 2
    printf("%d\n", a); // 1
    a %= 2; // a = a % 2
    printf("%d\n", a); // 1


    return 0;
}