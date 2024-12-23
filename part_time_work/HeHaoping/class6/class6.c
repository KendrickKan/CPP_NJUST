#include <stdio.h>
// stdio.h 标准输入输出头文件
// std 标准 standard
// i o 输入输出 input output

int main()
{
    // 输出
    printf("123");
    printf("a");
    // printf(""");
    // 转义字符：转换\后面的字符的含义
    // ""的含义控制字符串的开始和结束
    printf("\"\n");

    // 定义变量：指定变量的类型和名字
    int class1;    // 定义
    class1 = 1222; // 使用

    // 定义和使用同时进行
    int class2 = 123;

    printf("%d", class1);

    const int a = 3;
    //a = 4;
}