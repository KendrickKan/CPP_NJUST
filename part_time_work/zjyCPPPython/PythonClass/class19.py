# 集合
# 函数
# 内置函数
# 自定义函数
# 模块
print("class19.py")
# 集合 Set: 集合是一个无序的，[不重复]的数据集合
# 集合里面的元素不会重复，交集、并集、差集...
# 集合是用{}来表示的，元素之间用逗号分隔
# 为什么集合和字典都是用{}来表示呢？解释器是怎么区分集合和字典的呢？
# 字典是key:value的键值对，集合是无序的，不重复的元素集合
# 集合的定义 变量名 = {元素1, 元素2, 元素3, ...}
a = {1, 2, 3, 4, 5}
print(a)  # {1, 2, 3, 4, 5}
print(type(a))  # <class 'set'> 集合
# 创建空集合
# 创建空列表 a = []
# 创建空元组 a = ()
# 创建空字典 a = {}
a = {}
print(type(a))  # <class 'dict'> 字典
# 如果想要创建空集合，需要使用set()函数
a = set()
print(a)  # set()
print(type(a))  # <class 'set'> 集合
# 创建集合的其他方式
a = set([1, 2, 3, 4, 5])  # 通过列表创建集合
print(a)  # {1, 2, 3, 4, 5}
a = set((1, 2, 3, 4, 5))  # 通过元组创建集合
print(a)  # {1, 2, 3, 4, 5}
a = set("hello")  # 通过字符串创建集合
print(a)  # {'e', 'h', 'o', 'l'}

# 集合的操作
# 1. 集合的成员检测，in和not in
a = {1, 2, 3, 4, 5}
print(1 in a)  # True
print(6 in a)  # False
# 2. 集合的长度，len()函数
print(len(a))  # 5
# 3. 集合的遍历，for循环、
a = set("hello")
print(a)  # {'e', 'h', 'o', 'l'}
print(len(a))  # 4
for i in a:
    print(i)
# 4. 集合的添加元素，add()方法 是集合的方法，不是内置函数
a = {1, 2, 3, 4, 5}
print(a)  # {1, 2, 3, 4, 5}
a.add(6)
print(a)  # {1, 2, 3, 4, 5, 6}
a.add(6)  # 集合中的元素不会重复
print(a)  # {1, 2, 3, 4, 5, 6}
list1 = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5]
a = set(list1)
print(a)  # {1, 2, 3, 4, 5}
# 5. 集合的删除元素，remove()方法 是集合的方法，不是内置函数
a = {1, 2, 3, 4, 5}
print(a)  # {1, 2, 3, 4, 5}
a.remove(1)
print(a)  # {2, 3, 4, 5}
# a.remove(6)  # KeyError: 6
# 6. 集合的清空，clear()方法 是集合的方法，不是内置函数
a.clear()
print(a)  # set()
# 7. 集合的复制，copy()方法 是集合的方法，不是内置函数
a = {1, 2, 3, 4, 5}
b = a.copy()
print(b)  # {1, 2, 3, 4, 5}
# remove() 删除元素，如果元素不存在，会报错
# discard() 删除元素，如果元素不存在，不会报错
a = {1, 2, 3, 4, 5}
a.discard(6)
print(a)  # {1, 2, 3, 4, 5}

# 集合的运算
# 1. 集合的交集，intersection()方法
a = {1, 2, 3, 4, 5}
b = {4, 5, 6, 7, 8}
c = a.intersection(b)  # b.intersection(a)
print(c)  # {4, 5}
# 可以使用&符号来求交集
c = a & b
print(c)  # {4, 5}
# 2. 集合的并集，union()方法
c = a.union(b)  # b.union(a)
print(c)  # {1, 2, 3, 4, 5, 6, 7, 8}
# 可以使用|符号来求并集
c = a | b
print(c)  # {1, 2, 3, 4, 5, 6, 7, 8}
# 3. 集合的差集，difference()方法
c = a.difference(b)
print(c)  # {1, 2, 3}
c = b.difference(a)
print(c)  # {8, 6, 7}
# 可以使用-符号来求差集
c = a - b
print(c)  # {1, 2, 3}
c = b - a
print(c)  # {8, 6, 7}
# 4. 集合的对称差集，symmetric_difference()方法 不同时存在于a和b的元素
c = a.symmetric_difference(b)  # b.symmetric_difference(a)
print(c)  # {1, 2, 3, 6, 7, 8}
# 可以使用^符号来求对称差集
c = a ^ b
print(c)  # {1, 2, 3, 6, 7, 8}


# 函数 Function
# 函数是一段可以重复使用的代码块，可以实现特定功能
# Python内置函数
# print() input() type() len() range() int() str() float() list() tuple() set() dict() bool() ...
# 自定义函数
# 函数的定义
# c语言里面函数的定义
# 返回值类型 函数名(参数类型 参数名, 参数类型 参数名, ...) {
#     函数体
#     return 返回值;
# }
# Python里面函数的定义 def关键字
# def 函数名(参数1, 参数2, ...):
#     函数体
#     return 返回值
# 函数名：函数的名称，命名规则和变量名一样
# 参数：函数的输入，可以有0个、1个、多个参数
# 参数的类型：Python是弱类型语言，不需要指定参数的类型
# 函数体：函数的实现，函数的功能
# 返回值：函数的输出，可以有0个、1个、多个返回值


# 定义一个函数，实现两个数的加法，返回结果
def add_num(a, b):
    c = a + b
    return c


print(add_num(1, 2))


# 定义一个函数，实现输出hello world
def hello():
    print("hello world")


print(hello())  # 没有返回值，返回None，None是一个特殊的数据类型，表示空


# 返回多个值，多个值用逗号分隔，返回的是一个元组
# 定义一个函数，实现两个数的加法和减法，返回结果
def add_sub(a, b):
    c = a + b
    d = a - b
    return c, d


print(add_sub(1, 2))  # (3, -1)
# 可以使用多个变量接收返回值
e, f = add_sub(1, 2)
print(e)  # 3
print(f)  # -1

# 函数的参数
a = [1, 2, 3, 4, 5]  # 列表
b = "hello"  # 字符串
# a,b是没有类型的，仅仅是一个变量名
# 可更改(mutable)对象：列表、字典、集合
# 不可更改(immutable)对象：数字、字符串、元组
b = b + "world"


# 对于不可更改对象，函数的参数传递的是值，不会改变原来的值
# 对于可更改对象，函数的参数传递的是引用，会改变原来的值
# id()函数，获取变量的内存地址
def change(a):
    print(id(a))
    a = 10
    print(id(a))


a = 1
print(id(a))
change(a)
print(a)  # 1
# 在调用函数前后，形参和实参指向的是同一个内存地址，函数内部修改形参的值，不会影响实参的值，形参指向了新的内存地址


# 可变对象
def change_list(a):
    print(id(a))
    a.append(6)
    print(id(a))


a = [1, 2, 3, 4, 5]
print(id(a))
change_list(a)
print(a)  # [1, 2, 3, 4, 5, 6]
# 在调用函数前后，形参和实参指向的是同一个内存地址，函数内部修改形参的值，会影响实参的值，形参指向的是同一个内存地址


# 默认参数：函数定义时，给参数一个默认值
# 定义一个函数，实现两个数的加法，返回结果
def add_num(a, b=10):
    c = a + b
    return c


a = 1
b = 2
print(add_num(a, b))  # 3
print(add_num(20))  # 30
# 默认值只能放在参数列表的最后面


# 可变参数：函数定义时，不确定参数的个数
# *args：可变参数，可以接收0个、1个、多个参数，是一个元组
# 求几个数的和
def add_num(*args):
    sum = 0
    for i in args:
        sum += i
    return sum


print(add_num(1, 2, 3, 4, 5))

# lambda表达式：匿名函数，没有函数名，简化函数的定义
# lambda 参数1, 参数2, ... : 表达式

x = lambda a, b: a + b  # 定义一个lambda表达式, x是一个函数
print(x(1, 2))  # 3
# 匿名函数一般用在函数的参数比较少的情况下，函数体比较简单的情况下
# lambda表达式只能写一行代码，不能写多行代码