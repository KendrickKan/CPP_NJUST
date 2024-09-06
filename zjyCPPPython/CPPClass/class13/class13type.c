// 强制类型转换是把变量从一种类型转换为另一种数据类型。
// 例如，如果您想存储一个 long 类型的值到一个简单的整型中，您需要把 long 类型强制转换为 int 类型。
// 您可以使用强制类型转换运算符来把值显式地从一种类型转换为另一种类型，如下所示
// (type_name) expression
// 这里，type_name 必须是一个有效的 C 数据类型，可以是 char、int、float、double 等。
// expression 是要进行类型转换的值。
#include <stdio.h>

int main()
{
    int sum = 17, count = 5; // 17/5
    printf("sum = %d, count = %d\n", sum, count);
    printf("%f\n", (double)sum / count); // 强制类型转换，把sum转换为double类型，再除以count，double类型的结果
    // 17.0/5 = 3.400000
    // 17/5 = 3
    // int / int = int
    // double / int = double
    // 显示地把int转换为double

    // 隐式类型转换
    int i = 17;
    char c = 'c';                     /* ascii 值是 99 */
    float ic = i + c;                   // 隐式类型转换，把char转换为int，再相加
    printf("Value of ic : %f\n", ic); // 17 + 99 = 116
    // 因为编译器进行了整数提升，在执行实际加法运算时，把 'c' 的值转换为对应的 ascii 值
    // 如果是整数以浮点数输出，会截取小数点后面的部分
    // 若想要输出浮点数，需要强制类型转换

    return 0;
}