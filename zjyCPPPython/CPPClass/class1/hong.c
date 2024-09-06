#include <stdio.h> //输入输出 std标准 io输入输出 input output
// 宏定义PI 把一些常量定义为宏
#define PI 3.14159

int main()
{
    // printf的格式
    // printf(" 格式 控制字符串", 输出列表可以是多个变量);
    // 输出字符串
    printf("Hello World\n");
    // 输出整数 %d
    printf("100 = %d\n", 100);
    // 输出浮点数 %f 默认保留6位小数
    printf("PI = %f\n", 3.14159);
    // 输出自定义的保留小数位数 %.3f
    printf("PI = %.3f\n", PI);
    // 在一行里面输出多个变量 a = 1, b = 2
    printf("a = %d, b = %d\n", 1, 2);
    // 输出字符 %c
    printf("%c", 'A');
    return 0;
}