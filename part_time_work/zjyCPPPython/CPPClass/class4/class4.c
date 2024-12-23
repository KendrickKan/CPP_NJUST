// while 循环嵌套
// for 循环
// for 循环嵌套
// while for 循环嵌套
// goto 语句
// switch 语句
#include <stdio.h>

int main(int argc, char *argv[])
{
    // label1:
    printf("第4次课\n");
    printf("while 循环嵌套n");
    // while 循环嵌套
    // printf("\n");    // 换行
    // 1*1=1 换行
    // 1*2=2 2*2=4 换行
    // ... 换行
    // 1*9=9 2*9=18 3*9=27 ... 9*9=81 换行
    // x 控制行数
    // y 控制列数
    int x = 1;     // 控制行数
    while (x <= 9) // 控制行数
    {
        int y = 1;     // 控制列数
        while (y <= x) // 控制列数
        {
            printf("%d*%d=%d ", y, x, x * y);
            y++;
        }
        printf("\n");
        x++;
    }
    // while(循环条件){循环体}
    printf("for 循环n");
    // for 循环
    // for(初始化;循环条件;循环体){循环体}
    // 输出1-9
    for (int i = 1; i <= 9; i++)
    {
        printf("%d ", i);
    }

    // for 循环嵌套
    // a 控制行 b 控制列
    // a:1-9
    printf("\n");
    for (int a = 1; a <= 9; a++)
    {
        // b:1-a
        for (int b = 1; b <= a; b++)
        {
            printf("%d*%d=%d ", b, a, a * b);
            // break;
        }
        printf("\n");
    }
    // 输出1-9
    // while
    int i = 1;
    do
    {
        printf("%d ", i);
        i++;
    } while (i <= 9);

    int j = 1;
    for (; ;)
    {
        if (j > 9)
        {
            break;
        }
        printf("%d ", j);
        j++;
    }

    // while for
    // do while  for
    // while  do while  for 可以互相转换

    // for while循环嵌套 九九乘法表
    // 外for 内while
    // 外while 内for

    // break
    // continue
    // goto ：跳转到指定的标签

    for(int k = 1; k <= 9; k++)
    {
        if(k == 5)
        {
            // goto label1;
        }
        printf("%d ", k);
    }

    printf("\n");
    printf("switch 语句\n");
    // switch 语句
    // switch ：多分支选择语句

    // switch(表达式) 表达式的值与 case 后面的值相等时，执行 case 后面的语句，表达式只能是整型或字符型
    // switch表达式
    // {
    //      case 常量表达式1:
    //           语句1;
    //           break;(可选)
    //      case 常量表达式2:
    //           语句2;
    //           break;(可选)
    //      ...
    //      default:(可选)
    //           语句n;
    //           break;(可选)
    // }
    // 如果没有break，会继续执行下一个case，直到遇到break，或者执行到switch语句结束
    char grade = 'B';
    switch (grade)
    {
        case 'A':
            printf("优秀\n");
            break;
        case 'B':
            printf("良好\n");
            break;
        case 'C':
            printf("及格\n");
            goto label1;
            break;
        case 'D':
            printf("不及格\n");
            break;
        default:
            printf("无效的成绩\n");
    }
    label1:
    printf("switch  语句结束\n");

    return 0;
}