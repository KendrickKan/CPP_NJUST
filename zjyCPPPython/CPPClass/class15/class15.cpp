// c与c++的区别
// 1. c++是c的超集，c++支持c的所有语法
// 2. c++是面向对象的语言，c是面向过程的语言
// 3. c++的输入输出流stream，cin cout，c的输入输出函数scanf() printf()
// STL (Standard Template Library) 标准模板库
// 1. string，c++中的字符串；c中没有字符串类型，字符串是用字符数组实现的char str[100]
// 2. vector，c++中的动态数组；c中没有动态数组，数组的长度是固定的，数组的长度是在编译的时候就确定了
// 3. list，c++中的链表；c中没有链表，链表是用指针实现的
// 4. map，c++中的字典；c中没有字典，字典是用二维数组实现的
// 5. set，c++中的集合；c中没有集合，集合是用数组实现的
// 6. queue，c++中的队列；c中没有队列，队列是用数组实现的，先进先出
// 7. stack，c++中的栈；c中没有栈，栈是用数组实现的，先进后出
// 8. ...

// #include <stdio.h> // c语言的输入输出函数 scanf() printf() 都是在stdio.h头文件中定义的
#include <iostream> // c++的输入输出流 i put  o output stream

using namespace std; // 使用c++的命名空间

int main()
{
    printf("第15次课\n");
    // c++的输入输出流
    // cin cout 是c++的输入输出流，cin是输入流(类似于scanf)，cout是输出流(类似于printf)
    // cin cout 是c++的标准输入输出流，是c++的一部分，不是c++的关键字
    int a;
    // scanf("%d", &a);
    // 如何记忆cin >> a;的写法？
    // std::cin >> a;
    cin >> a;
    // printf("%d\n", a);
    // 如何记忆cout << a;的写法？
    // std::cout << a;
    cout << a << endl;
    // std::是c++的命名空间，c++中的所有标准库都在std命名空间中
    // using namespace std; // 使用c++的命名空间
    // c++的输出流cout，输出流是一个对象，cout是对象名，<<是输出运算符，a是输出的内容
    // c++的输入流cin，输入流是一个对象，cin是对象名，>>是输入运算符，a是输入的内容
    // C++的输入输出流相比于C语言的输入输出函数，更加方便，更加直观
    // C++的输入输出流是C语言的输入输出函数的封装，是C语言的输入输出函数的升级版
    // 同时输入多个变量
    int b, c;
    // scanf("%d %d", &b, &c);
    cin >> b >> c; // 用空格隔开, 用回车结束，输入多个变量
    // printf("%d %d\n", b, c);
    cout << b << "\n" << c << endl;
    // 流的状态
    // C++的输出换行符endl，C语言的换行符'\n'
    cout << endl; // 换行符
    cout << endl; // 换行符
    cout << endl; // 换行符
    cout << endl; // 换行符

    int d;
    // scanf("请输入一个整数：%d", &d);
    // cin >> "请输入一个整数：" >> d; // cin不支持这种写法，因为cin是输入流对象，不是函数
    // cin 只能接收输入的内容，不能输出提示信息
    cout << "请输入一个整数：";
    cin >> d;
    cout << d << endl;

    // cin cout和scanf printf不要混用
    // cin cout和scanf printf不能混用，cin cout是c++的输入输出流，scanf printf是c语言的输入输出函数

    // cpp是C++的文件后缀名，c是C语言的文件后缀名
    // c语言编译是用c的编译器，gcc
    // c++编译是用c++的编译器，g++

    return 0;
}