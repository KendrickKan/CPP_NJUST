# 第16次课
# python 开发环境配置
# 输出函数
# 变量：定义、赋值、类型
# 运算符：算数、比较、逻辑、赋值

# 什么是python,是一门解释型语言
# c语言和c++是编译型语言

# 什么叫编译型语言:编译型语言是指在程序运行之前需要一个专门的编译过程，将源代码编译成机器语言的过程，编译后的程序可以独立运行，不需要编译器的支持。
# // 【编译器】：gcc/g++ 将写好的c或者cpp代码编译成可执行文件exe，然后运行exe文件
# clang是苹果公司开发的编译器
# ms vc++是微软公司开发的编译器
# // 【编译过程】：源代码->预处理->编译->汇编->链接->可执行文件

# 什么叫解释型语言:解释型语言是指在程序运行时，通过【解释器】对源代码进行【逐行解释】，然后执行，不需要编译成机器语言，因此解释型语言的程序【不能脱离解释器】而独立运行。

# python是一门解释型语言，python的解释器是c语言写的，叫做cpython
# c语言写的解释器叫做cpython，然后在用解释器解释python代码，然后执行
# 除了cpython之外，还有其他的解释器，比如jpython，pypy，ipython

# Python的好处：
# 1.简单易学
# 2.免费开源
# 3.解释型语言的好处：不需要编译，直接运行

# printf("hello world\n"); // c语言的输出函数
# cout << "hello world" << endl; // c++的输出流
# print("hello world")  # python的输出函数
# 每一句话之后python不需要加分号

# 注释：单行注释和多行注释
# print("hello world\n") # 单行注释
"""
print("hello world\n")
print("hello world\n")
print("hello world\n")
"""  # 多行注释 三个单引号或者三个双引号
"""
print("hello world\n")
print("hello world\n")
print("hello world\n")
"""

# python 的输出函数：print()
# print()函数的参数可以是字符串，也可以是变量
# print()函数的参数之间用逗号隔开,会自动加空格
print("hello world", end="\n\n\n\n")
print(1, 2, 3)
# print()函数自带换行符
# 如果不想换行，可以在参数中加end="",end=""中的内容会在每次输出的最后加上

# 关键字：python中有一些单词是有特殊含义的，这些单词叫做关键字
# 关键字不能作为变量名
# 有哪些关键字
import keyword  # 导入关键字模块

# import和c语言的#include类似，导入一个模块
print(keyword.kwlist)  # 打印关键字列表

# 变量：变量是用来存储数据的
# 声明定义变量
# 变量名 = 变量值
a = 1
print(a)
# 和c语言的差别：c语言需要先声明变量的类型，然后再赋值；python不需要声明变量的类型，直接赋值即可

# 变量的命名规则：不能以数字开头，不能使用关键字，不能使用特殊字符。可以使用字母、数字、下划线。开头只能是字母或者下划线。变量名区分大小写。
A = 2
print(A)

# 变量的类型：整型、浮点型、字符串、布尔型
# 整型：int
# 浮点型：float
# 字符串：str
# 布尔型：bool; True和False
# 复数型：complex
# python四种数字类型：整型、浮点型、布尔型、复数型
# type()函数可以查看变量的类型
a = 1
print(type(a))
a = 1.2
print(type(a))
a = "hello world"
print(type(a))
a = True
print(type(a))
a = 1 + 2j
print(type(a))
# python是弱类型语言，变量的类型可以随时改变
# c语言是强类型语言，变量的类型不能随时改变
# python是动态语言，变量的类型可以随时改变

# 多个变量赋值
a = b = c = 1
print(a, b, c)
a, b, c = 1, 2, 3
print(a, b, c)

# 运算符：算数运算符、比较运算符、逻辑运算符、赋值运算符
# 算数运算符：+ - * / % ** //
a = 10
b = 3
print("+ - * / % ** //")
print(a + b)  # 加法，结果是整型
print(a - b)  # 减法，结果是整型
print(a * b)  # 乘法，结果是整型
print(a / b)  # 除法，结果是浮点型
print(a % b)  # 取余，结果是整型
print(a**b)  # 幂运算，结果是整型
print(a // b)  # 取整，结果是整型

# 比较运算符：== != > < >= <=，结果是布尔型
print("== != > < >= <=")
print(a == b)  # 判断是否相等
print(a != b)  # 判断是否不等
print(a > b)  # 判断是否大于
print(a < b)  # 判断是否小于
print(a >= b)  # 判断是否大于等于
print(a <= b)  # 判断是否小于等于

# c语言的逻辑运算符：&& || !
# 逻辑运算符：and or not，结果是布尔型
a = True
b = False
print("and or not")
print(a and b)  # 与运算，结果是False
print(a or b)  # 或运算，结果是True
print(not a)  # 非运算，结果是False
print(not b)  # 非运算，结果是True

# 赋值运算符：= += -= *= /= %= **= //=
a = 10
b = 3
print("= += -= *= /= %= **= //=")
a += 1  # a = a + 1
print(a)
a -= 1  # a = a - 1
print(a)
a *= 2  # a = a * 2
print(a)
a /= 2  # a = a / 2
print(a)
a %= 2  # a = a % 2
print(a)
a **= 2  # a = a ** 2
print(a)
a //= 2  # a = a // 2

# python没有自增自减运算符++ --
# a++和a--在python中是不合法的

# 运算符的优先级：算数运算符 > 比较运算符 > 逻辑运算符 > 赋值运算符
# 运算符的混合运算：先算数运算，再比较运算，再逻辑运算，最后赋值运算
a = 10
b = 3
c = 5
print(a + b > c and a - b < c)
# 先算数运算：a + b > c and a - b < c
# 再比较运算：13 > 5 and 7 < 5
# 再逻辑运算：True and False
# 最后赋值运算：False
# 在分不清优先级的时候，可以使用括号来改变优先级

# python的数据类型转换
# 隐式转换
a = 1
b = 1.2
c = a + b
print(c)
# 隐式转换：python会自动将整型转换成浮点型，然后再进行运算
a = 123
b = "456"
# c = a + b
# print(c) # 报错.整型和字符串类型运算结果会报错，输出 TypeError。 Python 在这种情况下无法使用隐式转换。

# 显示转换
# int() float() str() bool() complex() 用来转换数据类型的函数
a = 12.3
b = int(a)
print(b) # 12
print(type(b))
a = 12
b = float(a)
print(b) # 12.0
print(type(b))
a = 12
b = str(a)
print(b) # "12"
print(type(b))
# hex() oct() bin() 用来转换成十六进制、八进制、二进制的函数
a = 12
b = hex(a)
print(b) # 0xc
b = oct(a)
print(b) # 0o14
b = bin(a)
print(b) # 0b1100

# 类型转换和c语言的强制类型转换类似
# c语言：int a = (int)12.3;强制类型转换
# python：a = int(12.3);int()函数可以将浮点型转换成整型

# 成员运算符：in      not in
a = "hello world"
print("h" in a) # True # 判断h是否在a中
print("H" not in a) # False # 判断h是否不在a中

# 字符串
# 字符串是用单引号或者双引号括起来的字符序列
# c语言中没有字符串类型，c语言中的字符串是用字符数组来表示的
# c++中有字符串类型，c++中的字符串是用string类来表示的
# c语言 '' 代表字符， "" 代表字符串
# python中 '' 和 "" 都代表字符串
a = "hello world"
print(a)
a = 'hello world'
print(a)
# 三引号可以表示多行字符串
a = """hello
world"""
print(a)

# 访问字符串中的值，使用下标[]，下标从0开始
a = "hello world"
#    012345678910
print(a[0]) # h
print(a[5]) # " "
# 正向索引：从0开始，从左往右，依次递增
# 反向索引：从-1开始，从右往左，依次递减
print(a[-1]) # d
print(a[-5]) # w

# 字符串切片：字符串[起始下标:结束下标:步长]
a = "hello world"
#    012345678910
print(a[0:5]) # hello，从0开始，到5结束，不包括5，步长默认是1
print(a[0:5:2]) # hlo，从0开始，到5结束，不包括5，步长是2
print(a[5:]) # world，从5开始，到结束,结束下标可以省略
print(a[:5]) # hello，从0开始，到5结束，不包括5，起始下标可以省略

# 转义字符：\n \t \r \b \f \\ \' \" 都是在字符串中有特殊含义的字符
# \n 换行
# \t 制表符
# \r 回车
# \b 退格
# \f 换页
# \\ 反斜杠
# \' 单引号
a = "hello\nworld"
print(a)
a = "\\"
print(a)
a = '\''
print(a)
a = "'"
print(a)

# 字符串的运算：+ *
# + 字符串拼接
a = "hello"
b = "world"
c = a + b
print(c)

# * 字符串重复
a = "hello"
b = a * 3
print(b)

# 字符串的格式化输出，用%来格式化字符串，是在python2中的用法
# %s 字符串
# %d 整型
# %f 浮点型
# %c 字符
print("hello %s" % "world")
print("hello %d" % 123)
print("hello %.3f" % 12.3)
print("hello %c" % "w")
# % 多个参数
print("hello %s %d" % ("world", 123))

# 字符串的格式化输出，用format()函数来格式化字符串，是在python3中的用法
# {} 占位符，不用指定类型，自动识别，简单易用
print("hello {}".format("world"))
print("hello {} {}".format("world", 123))

# f-string：是在python3.6中引入的新的字符串格式化方法
# f-string是在字符串前加f或者F
a = 123
print(f"hello {a}")
a = a + a
print(F"hello {a} {a} {a}")

# 格式化字符串的好处：规定字符串的格式，但是字符串里面的内容提前不知道，所以可以填变量