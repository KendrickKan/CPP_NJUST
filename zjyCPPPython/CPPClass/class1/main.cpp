#include <iostream> //<>表示系统头文件
#include "mul.hpp" //""表示自定义头文件

using namespace std;
int main()
{
    int a = 0, b = 0;
    int result = 0;

    cout << "Pick two integers:";
    cin >> a;
    cin >> b;

    result = mul(a, b);

    cout << "The result is " << result << endl;
    return 0;
}
// 面向对象的编程

// 定义一个main.c add.h add.cpp 实现两个数相加
#include <stdio.h>
#include "add.h"

int main(){
    int result = add(1,2);
    printf("%d",result);
    return 0;
}