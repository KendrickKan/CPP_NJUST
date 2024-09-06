// STL (Standard Template Library) 标准模板库
// 1. string，c++中的字符串；c中没有字符串类型，字符串是用字符数组实现的char str[100]
// 2. vector，c++中的动态数组；c中没有动态数组，数组的长度是固定的，数组的长度是在编译的时候就确定了
// 3. list，c++中的链表；c中没有链表，链表是用指针实现的
// 4. map，c++中的字典；c中没有字典，字典是用二维数组实现的
// 5. set，c++中的集合；c中没有集合，集合是用数组实现的
// 6. queue，c++中的队列；c中没有队列，队列是用数组实现的，先进先出
// 7. stack，c++中的栈；c中没有栈，栈是用数组实现的，先进后出
// 8. ...

// 没有.h后缀，c++的头文件没有.h后缀
#include <iostream>
#include <string> // c++中的字符串头文件
#include <vector> // c++中的动态数组头文件

// struct 和 class 是类似的，struct是c语言中的关键字，class是c++中的关键字
// class String/vector
// {
//     // 定义了什么是字符串
//     // 定义了一些字符串方法=函数
//     // 定义了一些字符串运算符
// };
using namespace std;
int main()
{
    cout << "第15次课" << endl;
    cout << "STL" << endl;
    // string，c++中的字符串；c中没有字符串类型，字符串是用字符数组实现的char str[100]
    // 定义一个字符串 Hello World
    // char str[100] = "Hello World";
    // string 字符串类型
    string str1 = "Hello World";
    cout << str1 << endl;
    // string 方法
    // string 类型的变量可以调用方法
    // 拼贴字符串 c语言使用strcat()函数，c++使用+运算符
    string str2 = "Hello";
    string str3 = "World";
    string str4 = str2 + "!" + str3;
    cout << str4 << endl;
    // 复制字符串 c语言使用strcpy()函数，c++使用=运算符
    string str5 = str4;
    cout << str5 << endl;
    // 比较字符串 c语言使用strcmp()函数，c++使用==运算符 < > <= >=运算符
    string str6 = "ABC";
    string str7 = "ABC";
    if (str6 == str7)
    {
        cout << "str6 == str7" << endl;
    }
    // < > <= >=运算符 比较字符串的大小 ABC,AbC 是通过比较ASCII码值
    // 为什么C++中的字符串可以直接使用+运算符，=运算符，==运算符，< > <= >=运算符？
    // 因为C++中的字符串是一个类，类中可以定义成员变量，成员函数，运算符重载
    // 运算符重载：对已有的运算符重新定义
    // vector，c++中的动态数组；c中没有动态数组，数组的长度是固定的，数组的长度是在编译的时候就确定了
    // vector 动态数组，数组的长度是可以动态改变的
    // 使用方法和数组类似
    // int arr[5] = {1, 2, 3, 4, 5}; // 定义了一个int类型的数组，数组的长度是5
    // 定义一个vector
    // vector<type> name; // 定义一个type类型的动态数组，数组的长度是0
    // vector<int> v1; //定义了一个int类型的动态数组，数组的长度是0
    vector<int> v1 = {1, 2, 3, 4, 5}; // 定义了一个int类型的动态数组，数组的长度是5
    // vector<int> v1(5); // 定义了一个int类型的动态数组，数组的长度是5, 元素的值是0
    // vector<int> v1(5, 1); // 定义了一个int类型的动态数组，数组的长度是5, 元素的值是1
    // 怎么访问vector中的元素？ 和C语言的数组类似
    // vector的名字[下标]，下标还是从0开始
    cout << "v1的长度" << v1.size() << endl;
    cout << "v1[5]=" << v1[5] << endl;
    // vector的方法
    // 插入元素，删除元素，修改元素
    // 插入元素
    // v1.push_back(元素); // 在数组的末尾插入一个元素
    // name.push_back(元素); // 在数组的末尾插入一个元素
    v1.push_back(6); // 在数组的末尾插入一个元素6
    cout << "v1的长度" << v1.size() << endl;
    cout << "v1[5]=" << v1[5] << endl;
    // 删除元素
    // v1.pop_back(); // 删除数组的最后一个元素
    // name.pop_back(); // 删除数组的最后一个元素
    v1.pop_back(); // 删除数组的最后一个元素
    cout << "v1的长度" << v1.size() << endl;
    cout << "v1[5]=" << v1[5] << endl; // 虽然删除了最后一个元素，但是内存中还是有这个元素的值，但是这种方式是不安全的
    // 获取数组的长度
    // name.size(); // 获取数组的长度
    // vector的长度是动态变化的
    // 修改元素
    // v1[下标] = 元素; // 修改数组中的元素 和C语言的数组类似
    // name[下标] = 元素; // 修改数组中的元素
    cout << "v1[4]=" << v1[4] << endl;
    v1[4] = 0; // 修改数组中的第5个元素为0
    cout << "v1[4]=" << v1[4] << endl;
    // vector的方法
    // name.begin() // 获取数组的第一个元素的地址
    // name.end() // 获取数组的最后一个元素的地址
    // name.clear() // 清空数组 v1.clear() 清空v1数组
    // name.empty() // 判断数组是否为空 v1.empty() 判断v1数组是否为空, 如果v1为空，返回true，否则返回false
    bool isEmpty = v1.empty();
    cout << "v1是否为空" << isEmpty << endl;
    // v1.clear(); // 清空v1数组
    isEmpty = v1.empty();
    cout << "v1是否为空" << isEmpty << endl; // 1表示true，0表示false
    // 遍历数组
    for (int i = 0; i < v1.size(); i++)
    {
        cout << "v1[" << i << "]=" << v1[i] << endl;
    }
    // 还有遍历vector的方法
    // name.begin() // 获取数组的第一个元素的地址, 返回的是一个迭代器, 迭代器是一个指针,vector<int>::iterator是一个迭代器类型
    // name.end() // 获取数组的最后一个元素的地址
    for (auto i = v1.begin(); i != v1.end(); i++)
    // for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
    {
        cout << *i << endl; // *i表示i指向的元素,*取值运算符
    }
    // auto是c++11的关键字，自动推导类型

    // vector 的方法
    // name.insert(位置, 元素); // 在指定的位置插入元素
    // name.erase(位置); // 删除指定位置的元素
    // name.erase(开始位置, 结束位置); // 删除指定范围的元素
    // 位置指的是迭代器，地址
    v1.insert(v1.begin() + 2, 100); // 在第3个位置插入100
    for (int i = 0; i < v1.size(); i++)
    {
        cout << "v1[" << i << "]=" << v1[i] << endl;
    }
    v1.erase(v1.begin() + 3); // 删除第4个位置的元素
    for (int i = 0; i < v1.size(); i++)
    {
        cout << "v1[" << i << "]=" << v1[i] << endl;
    }
    v1.erase(v1.begin() + 1, v1.begin() + 3); // 删除第2个位置到第4个位置的元素，不包括第4个位置的元素 下标[1, 3) ,相当于删除的是第2个位置和第3个位置的元素
    for (int i = 0; i < v1.size(); i++)
    {
        cout << "v1[" << i << "]=" << v1[i] << endl;
    }

    auto a = 1;     // 自动推导类型 int
    auto b = 1.1;   // 自动推导类型 double
    auto c = 'a';   // 自动推导类型 char
    auto d = "abc"; // 自动推导类型 const char *

    // 3. list，c++中的链表；c中没有链表，链表是用指针实现的
    // 4. map，c++中的字典；c中没有字典，字典是用二维数组实现的
    // 5. set，c++中的集合；c中没有集合，集合是用数组实现的
    // 6. queue，c++中的队列；c中没有队列，队列是用数组实现的，先进先出
    // 7. stack，c++中的栈；c中没有栈，栈是用数组实现的，先进后出
    return 0;
}