// 字符串的操作
// 枚举
// 函数
// return 语句
// 传值调用
// 传引用调用
// 作用域: 全局变量 局部变量
// inline 函数
#include <stdio.h>
// #define MON 1
// #define TUE 2
// #define WED 3
// #define THU 4
// #define FRI 5
// #define SAT 6
// #define SUN 7
#define PI 3.14
// 会使得代码冗长，代码量多的时候，可以使用枚举
// 声明枚举类型
// 枚举如果不定义第一个变量的数值，默认从0开始
// 枚举如果从中间开始定义变量的值，那么第一个就是从0开始，然后从中间定义的变量往后都是+1
enum Week
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
} xyz;

// 先声明一下我们有这个函数，但是函数的具体定义，我们放在后面
// return_type function_name( parameter list );
int max_num(int a, int b);
void swap(int x, int y);
void swap2(int *a, int *b);

int xyz716 = 100; //全局变量：定义在函数外面,整个程序都可以使用


int main()
{
    printf("第7次课\n");
    printf("字符串\n");
    // 字符串如果要给整个字符串赋值 需要使用strcpy(s1,s2)函数, s1是目标字符串，s2是源字符串
    // 如果说赋值的是一个字符，就可以直接用=赋值
    // strcat(s1, s2) 把s2拼接到s1的后面
    // strlen(s) 返回字符串的长度
    // 字符串的长度是不包括'\0'的
    // strcmp(s1, s2) 比较两个字符串是否相等，相等返回0，如果s1>s2返回大于0，如果s1<s2返回小于0

    // 枚举 enum，c语言里面的基本数据类型，枚举类型
    // 定义一个星期的枚举类型 1-7 MON-SUN
    // MON 就为 1
    enum Week week715;
    week715 = MON;
    printf("%d\n", week715);
    xyz = SUN;
    printf("%d\n", xyz);

    // 函数 Function
    // 函数是一组一起执行一个或多个任务的一条或多条语句在一起的集合
    // 一个C语言 至少都有一个函数 主函数 main()函数
    // C语言都是以main函数为入口，开始执行程序的

    // 计算圆的面积
    float r = 10.0;
    float s = PI * r * r * r * r * r * r * r * r * r;
    float r2 = 20.0;
    // float s2 = .......;

    // 函数的作用：就把一系列常用的操作归纳在一起，以便于下一次可以直接去调用它。
    // 函数的定义格式
    // parameter使用,隔开,可以为空，函数体用不着外面的参数
    // return_type function_name(parameter list)
    // {
    //     body of the function //这个函数会执行的语句
    // }
    // return_type可以为空，也就是我们的函数并不需要返回东西，void
    // 返回 return XXX
    // 当函数里面遇到return 就会直接返回，结束整个函数了

    int x = 10;
    int y = 2;
    // function_name(parameter list)
    // 函数的调用，填的是实参，具有实际意义的
    int c = max_num(98, 99);
    // 形参 和 实参
    // 实参 实际上的参数，有具体的含义具体的值
    printf("%d\n", c);

    printf("交换函数\n");
    // 调用swap函数
    x = 1;
    y = 2;
    printf("交换前 x = %d, y = %d\n", x, y);
    swap(x, y);
    printf("交换后 x = %d, y = %d\n", x, y);
    // 传值调用：在调用函数时，实参把它的值传递给形参，形参的改变不会影响实参
    // 虽然在函数里面改变了x和y的值，但是对于main函数里面的x和y的值并没有改变

    // 引用调用：在调用函数时，实参的地址传递给形参，形参的改变会影响实参
    // & 取地址符号
    printf("交换函数2\n");
    printf("交换前 x = %d, y = %d\n", x, y);
    swap2(&x, &y);
    printf("交换后 x = %d, y = %d\n", x, y);

    printf("作用域\n");
    // 全局变量 局部变量
    // 全局变量 定义在函数外面的变量，整个程序都可以使用
    // 局部变量 定义在函数里面的变量，只能在函数里面使用
    // printf("%d\n", xyz715);
    printf("%d\n", xyz716);

    return 0;
}

// 定义了一个返回两个整数值较大的那个值 max_num 函数 工具
// a = 1 ; b = 2
// 形参 形式参数，起到一个造型上的作用 int a，int b
int max_num(int a, int b)
{
    int xyz715 = 0; //只是max_num函数里面的一个 局部变量
    printf("%d\n", xyz715);
    printf("%d\n", xyz716);
    if (a > b)
    {
        // 返回a
        return a;
    }
    else
    {
        // 返回b
        return b;
    }
    printf("Done!"); // 永远不会被执行，因为在之前就已经return
}

// 使用方法 function_name(parameter list)

// 声明 定义 调用

// 定义一个交换函数
void swap(int x, int y)
{
    int temp; // 先把x的值保存下来

    temp = x; /* 保存 x 的值 */
    x = y;    /* 把 y 赋值给 x */
    y = temp; /* 把 temp 赋值给 y */

    return;
}

// * 表示指针变量，指针变量是存储地址的变量
void swap2(int *a, int *b)
{
    int temp; // 先把x的值保存下来

    // *a 表示取出a指针指向的地址的值
    // 把a这个地址上面的值赋值给temp
    temp = *a; /* 保存 x 的值 */
    *a = *b;   /* 把 y 赋值给 x */
    *b = temp; /* 把 temp 赋值给 y */

    return;
}
