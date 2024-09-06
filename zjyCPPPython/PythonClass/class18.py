# 数字 Number
# 字符串 String
# 数据结构 Data Structure：组合数据的方式
# 列表 List []
# 元组 Tuple ()
# 字典 Dictionary {key1: value1, key2: value2, key3: value3, ...}
# 集合 Set
print("class18.py")
# 数字 Number 整数，浮点数，复数，布尔型
# 整数 int，python中整数没有大小限制，可以是一个很大的整数
# 浮点数 float，python中浮点数也没有大小限制，可以是一个很大的浮点数
# 复数 complex，python中复数由实部和虚部组成，虚部用j或J表示
# 布尔型 bool，True和False
# 数学函数，python中有很多数学函数，需要导入math模块
import math

# abs()函数，求绝对值
a = -10
print(abs(a))  # abs()函数不在math模块中，是python内置函数

# 要使用模块中的函数，需要使用 【模块名.函数名()】 的方式
# fabs()函数，求绝对值，返回浮点数
print(math.fabs(a))  # fabs()函数在math模块中

# ceil()函数，向上取整: 向上取整是指对一个数向上取最接近的整数
a = 1.2
# a = 1
print(math.ceil(a))

# floor()函数，向下取整: 向下取整是指对一个数向下取最接近的整数
a = 1.2
print(math.floor(a))

# round()函数，四舍五入
a = 1.2
print(round(a))  # round()函数是python内置函数
a = 1.5
print(round(a))

# exp()函数，求e的x次方, e是一个常数，约等于2.71828...
a = 1
print(math.exp(a))  # e的1次方=e

# log()函数，求自然对数, 默认以e为底
a = 1
print(math.log(a))  # 默认以e为底,返回值是浮点数
# log()函数 两个参数，第一个参数是x，第二个参数是底数
print(math.log(2, 10))  # 以10为底，2的对数

# log10()函数，求10为底的对数
a = 100
print(math.log10(a))  # == log(a, 10) ，返回值是浮点数

# pow(x,y)函数，求x的y次方 **运算符也可以求次方
a = 2
b = 3
print(math.pow(a, b))  # 2的3次方,返回值是浮点数

# sqrt()函数，求平方根
a = 4
print(math.sqrt(a))  # 4的平方根,返回值是浮点数

# sin()函数，求正弦值
# cos()函数，求余弦值
# tan()函数，求正切值

# max()函数，求最大值,参数可以是多个，返回值是最大值
print(max(1, 2, 3, 4, 5))

# min()函数，求最小值,参数可以是多个，返回值是最小值
print(min(1, 2, 3, 4, 5))

# sum()函数，求和,参数是一个序列，返回值是和
print(sum([1, 2, 3, 4, 5]))
print(sum(range(1, 6)))  # range(1, 6) 1 2 3 4 5

# math模块中的常数 使用 【模块名.常数名】 的方式
# math.pi 圆周率
print(math.pi)
# math.e 自然对数的底
print(math.e)

# 字符串 String

# 列表 List，是一个有序的集合，可以同时存储任意类型的数据，序列
# c语言里面数组是一个有序的集合，存储相同类型的数据 int a[5] = {1, 2, 3, 4, 5};

# python 列表的定义 变量名 = [元素1, 元素2, 元素3, ...]
a = [1, 2, 3, 4, 5]  # 定义了一个列表，列表中有5个元素，每个元素是一个整数
print(a)  # [1, 2, 3, 4, 5]
# 可以通过print()函数打印列表：python的print()函数可以打印任意类型的数据
# 如何查看一个变量的类型呢？type()函数
print(type(a))  # <class 'list'> 列表是一个数据类型
a = [1, 2, 3, 4, 5, "hello", 3.14, True]  # 列表中可以存储任意类型的数据
print(a)  # [1, 2, 3, 4, 5, 'hello', 3.14, True]

# 访问列表中的元素，列表是一个有序的集合，可以通过下标（索引）访问元素
# 列表的下标是从0开始的，最大下标是【列表长度-1】
a = [1, 2, 3, 4, 5]
#    0  1  2  3  4  5
#   -5 -4 -3 -2 -1 # 负数下标是从-1开始的，最大下标是-【列表长度】，从右往左
# 访问列表中的元素，变量名[下标]
print(a[0])  # 1
print(a[4])  # 5
print(a[-1])  # 5
print(a[-5])  # 1
# 访问越界，python会报错
# c语言不会报错，会访问到内存中的垃圾数据，随机值
# print(a[5])  # IndexError: list index out of range

# 切片，列表的切片，可以截取列表中的一部分元素
a = [1, 2, 3, 4, 5, "hello", 3.14, True]
#    0  1  2  3  4    5      6     7
#   -8 -7 -6 -5 -4   -3     -2    -1
# 切片的格式：变量名[起始下标:结束下标:步长]
# 起始下标是包含的，结束下标是不包含的，步长是可选的，默认是1
# 切片的结果是一个新的列表
print(a[0:5])  # 从下标0开始，到下标5结束，不包含下标5
print(a[:5])  # 默认起始下标是0
print(a[5:])  # 默认结束下标是列表的长度，一直到最后
print(a[:])  # 默认起始下标是0，结束下标是列表的长度，一直到最后
print(a[0:5:2])  # 步长是2，从下标0开始，到下标5结束，不包含下标5
# 可以使用负数下标
print(a[-5:-1])  # 从下标-5开始，到下标-1结束，不包含下标-1
# 下标 正数和负数混合使用
print(a[1:-2])  # 从下标1开始，到下标-2结束，不包含下标-2

# 更新列表中的元素，列表是一个可变的数据类型，可以增加、删除、修改元素
a = [1, 2, 3, 4, 5]
#    0  1  2  3  4
# 修改列表中的元素，变量名[下标] = 新值
print(a)  # [1, 2, 3, 4, 5]
a[0] = 10  # 修改列表中的元素
print(a)  # [10, 2, 3, 4, 5]
a[1:3] = [20, 30]  # 修改列表中的元素
print(a)  # [10, 20, 30, 4, 5]
# 增加列表中的元素，变量名.append(元素)
a.append(6)  # 在列表的最后增加一个元素
print(a)  # [10, 20, 30, 4, 5, 6]
# 删除列表中的元素，变量名.pop(下标)
a.pop()  # 删除最后一个元素
print(a)  # [10, 20, 30, 4, 5]
a.pop(1)  # 删除下标为1的元素
print(a)  # [10, 30, 4, 5]
# 删除列表中的元素，变量名.remove(元素)
a.remove(30)  # 删除元素30
print(a)  # [10, 4, 5]
a = [1, 2, 3, 4, 5, 3, 3]
print(a)  # [1, 2, 3, 4, 5, 3, 3]
# 如果同时有多个相同的元素，只删除第一个
a.remove(3)
print(a)  # [1, 2, 4, 5, 3, 3]
# 如果元素不存在，python会报错
# a.remove(6)  # ValueError: list.remove(x): x not in list
# 删除列表中的元素，del 变量名[下标]
del a[1]  # 删除下标为1的元素
print(a)  # [1, 4, 5, 3, 3]
# 插入元素，变量名.insert(下标, 元素)
a.insert(1, 2)  # 在下标为1的位置插入元素2
print(a)  # [1, 2, 4, 5, 3, 3]

# 列表的运算符
# +运算符，列表相加，相当于两个列表相加
a = [1, 2, 3]
b = [4, 5, 6]
print(a + b)  # [1, 2, 3, 4, 5, 6]
# *运算符，列表相乘，相当于列表重复
a = [1, 2, 3]
print(a * 3)  # [1, 2, 3, 1, 2, 3, 1, 2, 3]
# in运算符，判断元素是否在列表中
a = [1, 2, 3]
print(1 in a)  # True
print(4 in a)  # False
# not in运算符，判断元素是否不在列表中
# len()函数，求列表的长度
a = [1, 2, 3]
print(len(a))  # 3

# 列表的遍历
# for循环遍历列表
# for 变量名 in 序列: 每一次循环，变量名是序列中的一个元素
a = [1, 2, 3, 4, 5]
for i in a:
    print(i)

# while循环遍历列表
a = [1, 2, 3, 4, 5]
i = 0  # 下标
while i < len(a):  # 下标小于列表的长度才遍历
    print(a[i])  # 访问列表中的元素
    i += 1  # 下标加1

# max()函数，求最大值
a = [1, 2, 3, 4, 5]
print(max(a))  # 5
# min()函数，求最小值
print(min(a))  # 1
# sum()函数，求和
print(sum(a))  # 15

# 列表的函数：append() pop() remove() insert()
# 列表的方法：count() index() sort() reverse() clear() copy()
# count()方法，统计元素在列表中出现的次数
a = [1, 2, 3, 4, 5, 3, 3]
#    0  1  2  3  4  5  6
print(a.count(5))  # 1
print(a.count(3))  # 3
# index()方法，查找元素在列表中的下标, 返回第一个元素的下标
print(a.index(5))  # 4
print(a.index(3))  # 2
# sort()方法，对列表进行排序，默认升序排序
a = [3, 2, 1, 5, 4]
print(a)  # [3, 2, 1, 5, 4]
a.sort()  # 默认升序排序
print(a)  # [1, 2, 3, 4, 5]
# sort()方法，对列表进行排序，降序排序
a.sort(reverse=True)  # 降序排序
print(a)  # [5, 4, 3, 2, 1]
# reverse()方法，对列表进行反转
a = [1, 2, 3, 4, 5, 3, 3]
print(a)  # [1, 2, 3, 4, 5, 3, 3]
a.reverse()  # 反转
print(a)  # [3, 3, 5, 4, 3, 2, 1]
# clear()方法，清空列表
a.clear()
print(a)  # []
# copy()方法，复制列表,返回一个新的列表
a = [1, 2, 3, 4, 5]
b = a.copy()  # 复制列表
print(b)  # [1, 2, 3, 4, 5]

# 列表的嵌套,多维数组
# 列表中的元素也可以是一个列表
# a = [[],[],[],...]
a = [[1, 2, ["a", "c"]], [4, 5, 6, "d"], [7, 8, 9]]
#     0                  1                2
print(a[0])  # [1, 2, 3]
# 访问3这个元素
print(a[0][2])  # 3
print(a[1][1])  # 5
print(a[0][2][1])  # c
# 体现了列表的灵活性，可以存储任意类型的数据，可以存储多维数组
# 创建空列表
a = []

# 列表 []，是一个有序的集合，可以同时存储任意类型的数据，序列,可变的数据类型

# 元组 Tuple ()，是一个有序的集合，可以同时存储任意类型的数据，序列,不可变的数据类型
# 【定义好了元组，不能修改元组中的元素】
# 元组的定义 变量名 = (元素1, 元素2, 元素3, ...)
a = (1, 2, 3, 4, 5)  # 定义了一个元组，元组中有5个元素，每个元素是一个整数
print(a)  # (1, 2, 3, 4, 5)
print(type(a))  # <class 'tuple'> 元组
# 有序 也可以通过下标访问元素
# 尝试修改元组中的元素，python会报错
# a[0] = 10  # TypeError: 'tuple' object does not support item assignment
# 创建空元组
a = ()
print(a)  # ()
print(type(a))  # <class 'tuple'> 元组
# 支持元组的拼接
a = (1, 2, 3)
b = (4, 5, 6)
print(a + b)  # (1, 2, 3, 4, 5, 6) ，返回一个新的元组
# 元组剩下的操作和列表一样


# 字典 Dictionary {}，是一个【无序】的集合，可以同时存储任意类型的数据，
# 键值对 key-value，key是唯一的，value可以重复，可以通过key访问value
# 【key是不可变的数据类型】
# 字典的定义 变量名 = {key1: value1, key2: value2, key3: value3, ...}
a = {"name": "zhangsan", "age": 18, "grade": "A"}
# 定义了一个字典，字典中有3个键值对，三个元素
print(a)  # {'name': 'zhangsan', 'age': 18, 'grade': 'A'}
print(type(a))  # <class 'dict'> 字典
# 无序 不能通过下标访问元素，只能通过key访问value
# 通过key访问value，变量名[key]
print(a["name"])
print(a["age"])
print(a["grade"])
# 字典和C语言中的结构体有点像，都是存储多个数据的数据类型
# 修改字典中的元素，变量名[key] = 新值
a["name"] = "lisi"
print(a)  # {'name': 'lisi', 'age': 18, 'grade': 'A'}
# 创建空字典
a = {}
print(a)  # {}
print(type(a))  # <class 'dict'> 字典
# 增加字典中的元素，变量名[key] = value
a["name"] = "zhangsan"
print(a)  # {'name': 'zhangsan'}
a["age"] = 18
print(a)  # {'name': 'zhangsan', 'age': 18}

# 字典的函数：len()函数，求字典的长度
a = {"name": "zhangsan", "age": 18, "grade": "A"}
print(len(a))  # 3

# key 不能有重复的，而value可以有重复的
a = {"name": "zhangsan", "age": 18, "grade": "A", "name": "lisi"}
print(a)  # {'name': 'lisi', 'age': 18, 'grade': 'A'} key不能有重复的，后面的会覆盖前面的
a = {"name": "zhangsan", "age": 18, "grade_1": "A", "grade_2": "A"}
print(a)  # {'name': 'zhangsan', 'age': 18, 'grade_1': 'A', 'grade_2': 'A'}

# 无序的，所以不能用下标访问元素，不能用while循环遍历字典
# for循环遍历字典
# for 变量 in 序列：每一次循环，变量是序列中的一个元素
a = {"name": "zhangsan", "age": 18, "grade": "A"}
for i in a:
    # i是key
    print(i)  # i是key
    print(a[i])  # a[i]是value
