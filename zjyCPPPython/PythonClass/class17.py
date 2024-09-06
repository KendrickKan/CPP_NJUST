# 顺序结构: 从上到下执行;c语言也是从上到下执行
# 选择结构 缩进格式
# -单分支选择结构
# -双分支选择结构
# -多分支选择结构
# 输入函数input()
# 循环结构
# -while循环
# -for循环
# --range()函数，生成一个序列
# -循环嵌套
# -break、continue、pass语句
# -死循环、无限循环
print("class17.py")
# 选择结构
print("choose structure")
# 单分支选择结构 if
# c语言的if语句 if(条件){语句}
# if (1 > 0)
# {
#     printf("1 > 0\n");
# }
# python的if语句 if 条件: 语句
# 缩进格式：python中没有{}，用缩进来表示代码块
if 1 > 0:
    print("1 > 0")
    print("2 > 0")
    print("3 > 0")
    print("4 > 0")
print("5 > 0")  # 不在if语句块中

# 双分支选择结构 if else
# c语言的if else语句 if(条件){语句1}else{语句2}
# if (1 > 0)
# {
#     printf("1 > 0\n");
# }
# else
# {
#     printf("1 <= 0\n");
# }
# python的if else语句 if 条件: 语句1 else: 语句2
if 1 > 0:
    print("1 > 0")
else:
    print("1 <= 0")

# 多分支选择结构 if elif... else
# c语言的if else if else语句 if(条件1){语句1}else if(条件2){语句2}else{语句3}
# if (1 > 0)
# {
# printf("1 > 0\n");
# }
# else if (1 == 0)
# {
#     printf("1 == 0\n");
# }
# else
# {
#     printf("1 < 0\n");
# }
# python的if elif... else语句 if 条件1: 语句1 elif 条件2: 语句2 else: 语句3
a = 1
if a > 0:
    print("a > 0")
elif a == 0:
    print("a == 0")
elif a < 0:
    print("a < 0")
else:
    print("a is not a number")
# python 相比于c语言，更加简洁，更加优雅，更加直观易读

# c语言的switch case语句
# python 没有switch case语句。在3.10版本中，引入了match case语句
# switch case 语句可以用if elif... else语句来代替

# if elif 后面的条件可以是比较表达式，也可以是逻辑表达式，也可以是布尔值。因为逻辑表达式最后计算的结果是布尔值
# 比较表达式：== != > < >= <=
# 逻辑表达式：and or not
# 布尔值：True False
# 实质上，if elif 后面的条件是布尔值
# 可以是多个表达式组合成的逻辑表达式

# 选择结构的嵌套
# python中的if语句可以嵌套
a = 1
b = 2
if a > 0:
    if b > 0:
        print("a > 0 and b > 0")
    else:
        print("a > 0 and b <= 0")
else:
    print("a <= 0")
# 通过缩进来表示代码块，代码块可以嵌套
# 通过缩进的数量来表示代码块的层次

# 输入函数input()
# c语言中的输入函数scanf()
# c++ 中的输入函数cin >>
# python中的输入函数input()

# input()函数的返回值是字符串类型
# input()函数的参数是提示信息,可以是字符串类型，仅仅是提示信息，会在屏幕上显示

# a = int(input("please input a number:"))
# a = input("please input a number:")
print(a)
print(type(a))  # <class 'str'> 字符串类型
# python是弱类型语言，变量的类型可以随时改变
# python 显示类型转换函数 int() float() str()
a = int(a)
print(type(a))  # <class 'int'> 整型

# 循环结构
print("loop structure")
# c语言中的循环结构: for循环、while循环、do while循环
# python中的循环结构: while循环、for循环
# python中没有do while循环

# python中的while
# c语言中的while循环 while(条件){语句} 当条件为真时，执行语句
# a = 1
# while (a > 0)
# {
#     printf("a > 0\n");
#     a--;
# }
# python中的while循环 while 条件: 语句 当条件为真时，执行语句
# 语句是一个代码块，用缩进来表示代码块
a = 5
while a > 0:
    print("a > 0")
    a -= 1

# python中的for循环
# c语言中的for循环 for(初始化;循环条件;增量){语句} 初始化只执行一次，条件为真时，执行语句，增量每次循环执行一次
# for (int i = 0; i < 5; i++)
# {
#     printf("i = %d\n", i);
# }
# c语言中的 初始化、循环条件、增量 能够构成一个序列 0 1 2 3 4
# python中的for循环 for 变量 in 序列: 语句
# 从序列中取出一个元素，赋值给变量，执行语句
for i in [0, 1, 2, 3, 4]:
    print("i = ", i)

# 有没有一种方法，可以生成一个序列呢？不要手动输入序列
# range()函数
# range()函数可以生成一个序列，返回值就是一个序列
# range(参数) 填一个参数，表示生成一个从0开始，到【参数-1】结束的序列
range(6)  # 0 1 2 3 4 5 +1
for i in range(6):
    print("i = ", i)
# range(起始值，结束值) 生成一个从起始值开始，到【结束值-1】结束的序列
range(2, 5)  # 2 3 4 +1
for i in range(2, 5):
    print("i = ", i)
# range(起始值，结束值，步长) 生成一个从起始值开始，到【结束值-1】结束的序列，步长是步长
range(2, 10, 2)  # 2 4 6 8 步长2
for i in range(2, 10, 2):
    print("i = ", i)

# 扩展while循环 while else
# c语言中没有while else
# python中的while else 当while循环正常结束时，执行else语句
a = 2
while a > 0:
    print("a > 0")
    a -= 1
else:
    print("a <= 0")
# 扩展for循环
# c语言中没有for else
# python中的for else 当for循环正常结束时，执行else语句
for i in range(3):
    print("i = ", i)
else:
    print("for loop is over")

# for 循环中的序列可以是字符串，字符串是一个字符序列
for i in "hello":
    print(i, end=" ")  # print自带换行

print()


# 循环嵌套
# 99乘法表
# 为什么要用循环嵌套？因为乘法表是一个二维表，需要两个维度来表示，第一个维度是行，第二个维度是列
# 乘法表是一个9行9列的表
# 1 * 1 = 1 1-1
# 1 * 2 = 2 2 * 2 = 4 2-2
# 1 * 3 = 3 2 * 3 = 6 3 * 3 = 9 3-3
# 1 * 4 = 4 2 * 4 = 8 3 * 4 = 12 4 * 4 = 16
# ...
# 1 * 9 = 9 2 * 9 = 18 3 * 9 = 27 ... 9 * 9 = 81 9-9
# 乘法表的特点：行和列相同，行和列的乘积相同
# 乘法表的行和列都是从1开始，到9结束
# i 表示行，j 表示列
# i 从1开始，到9结束
# j 在第i行中，从1开始，到i结束
# 外层循环控制行
for i in range(1, 10):
    # 内层循环控制列
    # range的第二个参数是i+1，表示从1开始，到i结束
    for j in range(1, i + 1):
        print(j, "*", i, "=", i * j, end=" ")
    print()  # 换行,因为print自带换行

# 外层循环控制行
i = 1
while i < 10:
    # 内层循环控制列
    j = 1
    while j <= i:
        print(j, "*", i, "=", i * j, end=" ")
        j += 1
    print()  # 换行
    i += 1

# break、continue、pass语句
# break语句：跳出循环
# continue语句：跳过本次循环，进入下一次循环
# pass语句：占位语句，什么也不做
# 和c语言的break、continue、pass语句功能一样
# break、continue、pass语句只能在循环中使用
for i in range(10):
    if i == 5:
        break  # 遇到5时，跳出结束循环
    print(i, end=" ")
else:
    print("break for loop is over")  # 不会执行,因为break跳出循环,for循环没有正常结束

print()
# continue语句
for i in range(10):
    if i == 5:
        continue  # 遇到5时，跳过本次循环，进入下一次循环
    print(i, end=" ")
else:
    print(
        "continue for loop is over"
    )  # 执行,因为continue跳过本次循环没有结束整个循环,for循环正常结束

# pass语句
for i in range(10):
    if i == 5:
        pass  # 什么也不做
    print(i, end=" ")
else:
    print("pass for loop is over")

# 死循环：循环条件永远为真，循环永远不会结束
while 1 > 0:
    print("1 > 0")
    break  # 退出死循环

# 写代码的时候，要注意不要写到死循环，否则会导致程序卡死

# 无限循环：不确定循环次数，循环次数不确定，可以人为的控制循环次数
a = 1
while a != 0:
    print(a)
    a = int(input("please input a number:"))
