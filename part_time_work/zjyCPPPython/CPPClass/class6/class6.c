// 字符串
// 结构体
// 联合体
// 枚举
// typedef

#include <stdio.h>
#include <string.h>

// 定义一个结构体类型 Student
struct Student
{
    int id;        // 学号 4字节
    char name[10]; // 姓名 10字节
    int age;       // 年龄 4字节
    float score;   // 分数 4字节
} stu4, stu6;      // 声明两个Student类型的变量stu4和stu5, 每个变量用逗号隔开
// 在定义的时候就可以声明变量

int ax; // 声明了一个整型变量

// 结构体的默认值是随机值，不是0

union Data
{
    int i;        // 4字节
    float f;      // 4字节
    char str[20]; // 20字节
} data2;          // 声明一个联合体变量data2

int main()
{
    printf("第6次课\n");
    printf("字符串\n");
    // 字符串
    // 字符串=字符数组=一串字符
    char arr1[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    // 字符串的结束标志是'\0'，ASCII码是0，必须要有结束标志
    char arr2[] = "abcde"; //""表示字符串
    // '\0'默认添加在字符串的末尾
    // 'a' "a"
    printf("%d\n", sizeof('a'));     // 一个字符是1个字节，但是单字符是以整型存储的，所以sizeof('a')是4
    printf("%d\n", sizeof("abcde")); // 6 字符串的长度是5，加上结束标志'\0'是6
    // 字符串是以字符数组的形式存储的，所以sizeof("abcde")是6=5+1
    printf("%c\n", arr2[5]); // 一个字节

    // 字符串的方法（函数）
    char arr3[7] = "hello";
    printf("%c\n", arr3[0]);      // null字符
    printf("%d\n", sizeof(arr3)); // 长度是12字节 没有被初始化的部分是空字符
    printf("%s\n", arr3);         // hello
    char arr4[12] = "world";
    // 字符串拼接 strcat(s1, s2) 把s2拼接到s1的后面
    strcat(arr3, arr4);
    printf("%s\n", arr3); // helloworld
    printf("%d\n", sizeof(arr3));
    // 虽然arr3的长度是7，但是拼接了world之后，arr3输出的长度还是7，因为arr3的长度是7，但是arr3的内存空间是12字节
    // 字符串的复制 strcpy(s1, s2) 把s2复制到s1
    char arr5[12] = "hello";
    printf("%s\n", arr5); // hello
    char arr6[12] = "world";
    strcpy(arr5, arr6);
    printf("%s\n", arr5);
    // 字符串长度 strlen(s) 返回s的长度，不包括'\0' 也不包括后面未初始化的部分
    char arr7[12] = "hello";
    printf("%d\n", strlen(arr7)); // 5
    printf("%d\n", sizeof(arr7)); // 12
    // sizeof(arr7)是12，但是strlen(arr7)是5，因为strlen()函数只计算字符串的长度，不包括'\0'和后面未初始化的部分，而sizeof()函数计算的是整个数组的长度

    // 字符串比较 strcmp(s1, s2) 比较s1和s2的大小，如果s1>s2返回正数，s1<s2返回负数，s1=s2返回0
    // 字符串比较是按照ASCII码比较的
    // 大写字母的ASCII码比小写字母的ASCII码小
    char c1 = 'a';           // 97
    char c2 = 'B';           // 66
    printf("%d\n", c1 < c2); // ture 1
    printf("%d\n", c1 > c2); // false 0
    char arr8[12] = "world";
    char arr9[12] = "world";
    printf("%d\n", strcmp(arr8, arr9)); // 0
    // 字符串比较大小,从头开始比较，如果有不同的字符，比较ASCII码，如果s1>s2返回正数，s1<s2返回负数，s1=s2返回0

    // 字符串的遍历 下标还是从0开始
    char arr10[6] = "hello";
    for (int i = 0; i < strlen(arr10); i++)
    {
        printf("%c\n", arr10[i]);
    }

    // 字符串空格的问题,字符串中的空格也是字符,字符串输入的时候，空格会被当做结束标志
    char arr11[12] = "hello world"; // 默认在最后会添加上'\0'
    printf("%s\n", arr11);          // hello world
    char arr12[12] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
    printf("arr12%s\n", arr12); // hello world
    // string类

    // int float double char bool
    int a; // 声明了一个整型变量
    a = 1; // 赋值
    printf("结构体\n");
    // 结构体 struct
    // 数组里面存的是{相同类型}的数据，结构体里面存的是不同类型的数据
    // 结构体是用户自定义的数据类型,可以存放不同类型的数据
    // struct 结构体名{数据类型 成员名1; 数据类型 成员名2;...};
    // 把学号，姓名，年龄，分数放在一起,组合成一个学生的信息,就形成了一个新的数据类型 Student
    // Student 结构体类型的名字 是我们自己定义的 类似于int
    // stu1 是Student类型的变量
    struct Student stu1 = {1, "zhang", 18, 99.9}; // 声明然后再初始化
    // 访问结构体成员
    // 结构体变量名.成员名
    // . 叫做成员运算符
    printf("%d\n", stu1.id);      // 访问结构体成员
    printf("%s\n", stu1.name);    // 访问结构体成员
    printf("%d\n", stu1.age);     // 访问结构体成员
    printf("%.1f\n", stu1.score); // 访问结构体成员

    struct Student stu2;          // 声明一个Student类型的变量stu2
    printf("%d\n", stu2.id);      // 访问结构体成员
    printf("%s\n", stu2.name);    // 访问结构体成员
    printf("%d\n", stu2.age);     // 访问结构体成员
    printf("%.1f\n", stu2.score); // 访问结构体成员
    // 如果没有初始化，结构体的成员是随机值,不是0
    stu2.id = 2;                  // 初始化
    strcpy(stu2.name, "li");      // 初始化 结构体的成员是字符串的时候，不能直接赋值，要用strcpy()函数
    stu2.age = 19;                // 初始化
    stu2.score = 98.9;            // 初始化
    printf("%d\n", stu2.id);      // 访问结构体成员
    printf("%s\n", stu2.name);    // 访问结构体成员
    printf("%d\n", stu2.age);     // 访问结构体成员
    printf("%.1f\n", stu2.score); // 访问结构体成员

    struct Student stu3 = {3, "wang", 20, 97.9}; // 声明然后再初始化
    printf("结构体数组\n");
    // 结构体数组,数组里面的元素是结构体类型的
    struct Student stulist[3] = {stu1, stu2, stu3}; // 结构体数组
    // 访问结构体数组的元素的某个成员 要输出stu1的学号
    printf("%d\n", stulist[0].id); // 访问结构体数组的元素的某个成员
    printf("%d\n", stu1.id);       // 访问结构体成员

    // 循环遍历结构体数组,输出所有学生的分数,每个信息在一行,输出完一个学生之后换行
    for (int i = 0; i < 3; i++)
    {
        printf("%f\n", stulist[i].score);
    }

    // 结构体大小的计算
    // 结构体的大小是所有成员的大小之和
    // sizeof() 计算数据类型或者变量的长度,单位是字节
    // 4 + 10 + 4 + 4 = 22
    printf("%d\n", sizeof(struct Student)); // 24
    // 结构体的大小他是会自动对齐的，结构体的大小是所有成员的大小之和，但是结构体的大小是4的倍数
    // 结构体的大小可能会受到编译器的优化和对齐规则的影响，编译器可能会在结构体中插入一些额外的填充字节以对齐结构体的成员变量，以提高内存访问效率。
    // 因此，结构体的实际大小可能会大于成员变量大小的总和，如果你需要确切地了解结构体的内存布局和对齐方式，可以使用 offsetof 宏和 __attribute__((packed)) 属性等进一步控制和查询结构体的大小和对齐方式。

    // '\n' 换行符
    // '\0' 字符串的结束标志
    // '\t' 制表符
    // '\b' 退格
    printf("%d\n", 1);
    printf("\n");
    printf("%d", 2);

    // 联合体 union
    // 联合体和结构体很像，都是用户自定义的数据类型，都可以存放不同类型的数据
    // union 联合体名{数据类型 成员名1; 数据类型 成员名2;...};
    printf("联合体\n");
    // 4 4 20 = 28 但是联合体的大小是最大的成员的大小 20
    printf("%d\n", sizeof(union Data)); // 20
    // 联合体和结构体的区别是，结构体的成员是共享的，是同时存在的，联合体的成员是互斥的，是只能存在一个的
    // 联合体的大小是最大的成员的大小
    union Data data1;           // 声明一个联合体变量data1
    data1.i = 1;                // 赋值
    data1.f = 2.0;              // 赋值
    strcpy(data1.str, "hello"); // 赋值
    printf("%d\n", data1.i);    // 访问联合体成员
    printf("%f\n", data1.f);    // 访问联合体成员
    printf("%s\n", data1.str);  // 访问联合体成员
    // 为什么前两个输出的是乱码，因为联合体的成员是互斥的
    // 当有一个成员赋值的时候，其他成员的值就会被覆盖
    data1.i = 1;                // 赋值
    printf("%d\n", data1.i);    // 访问联合体成员
    data1.f = 2.0;              // 赋值
    printf("%f\n", data1.f);    // 访问联合体成员
    strcpy(data1.str, "hello"); // 赋值
    printf("%s\n", data1.str);  // 访问联合体成员

    // struct Student stu4; // 声明一个Student类型的变量stu4
    stu4.id = 4;               // 初始化
    strcpy(stu4.name, "zhao"); // 初始化
    stu4.age = 21;             // 初始化
    stu4.score = 96.9;         // 初始化

    struct Student stu5;     // 声明一个Student类型的变量stu5,在mian里面声明的，是随机值
    printf("%d\n", stu5.id); // 访问结构体成员
    printf("%s\n", stu5.name);
    printf("%d\n", stu5.age);
    printf("%.1f\n", stu5.score);
    // stu6是在结构体定义的时候声明的，默认值是0
    printf("%d\n", stu6.id); // 访问结构体成员
    printf("%s\n", stu6.name);
    printf("%d\n", stu6.age);
    printf("%.1f\n", stu6.score);

    // ax是在main函数外面声明的，默认值是0
    printf("%d\n", ax); // 0
    int bx;
    printf("%d\n", bx); // 随机值
    // 声明位置不同，值也不同，main函数外面声明的默认值是0，main函数里面声明的默认值是随机值
    return 0;
}