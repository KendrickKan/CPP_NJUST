// 传递指针给函数
// 排序算法
// C++ 输入输出流
#include <stdio.h>

void swap(int x, int y);
void swap2(int *x, int *y);

int main()
{
    printf("第14次课\n");
    // 传递指针给函数
    int a = 1, b = 2;
    printf("交换前 a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("交换后 a = %d, b = %d\n", a, b);
    // 函数 传值调用 引用调用
    // 传值调用：在调用函数时，实参把它的值传递给形参，形参的改变不会影响实参
    // 虽然在函数里面改变了x和y的值，但是对于main函数里面的a和b的值并没有改变
    // 如果想要改变main函数里面的a和b的值，可以使用引用调用
    // 引用调用：在调用函数时，【实参的地址】传递给形参，形参的改变会影响实参
    // 地址，指的是内存地址；a和b在内存中是有唯一的地址的
    // 所以函数的参数就应该是指针类型
    printf("交换函数2\n");
    printf("交换前 a = %d, b = %d\n", a, b);
    // & 取地址符号
    swap2(&a, &b);
    printf("交换后 a = %d, b = %d\n", a, b);
    return 0;
}

void swap(int x, int y)
{
    int temp; // 先把x的值保存下来

    temp = x; /* 保存 x 的值 */
    x = y;    /* 把 y 赋值给 x */
    y = temp; /* 把 temp 赋值给 y */

    return;
}

// 传递指针给函数
// 传递指针给函数，可以直接修改实参的值
void swap2(int *x, int *y)
{
    // x就代表 传进来的第一个参数的地址
    // *是取值符号，取出地址里面的值，虽然这个地址也是通过值传进来的，但是我们可以通过这个地址去修改这个【地址里面的值】，所以就可以修改实参的值
    // *x就代表 传进来的第一个参数的值
    int temp; // 先把x的值保存下来

    temp = *x; /* 保存 x 的值 */
    *x = *y;   /* 把 y 赋值给 x */
    *y = temp; /* 把 temp 赋值给 y */

    return;
}