# Python模块 和 C语言中的头文件类似，是一个包含Python代码的文件，后缀名是.py
# 常用的Python模块
# 如何使用Python模块
# 导入模块
# import 模块名
# 使用模块中的函数
# 模块名.函数名()
# 使用模块中的变量
# 模块名.变量名

# Python模块
# 随机数模块 random 生成随机数
import random

# 生成随机数的函数 random.randint(a, b) 生成一个a到b之间的随机整数
print(random.randint(1, 10))  # 生成一个1到10之间的随机整数
# 生成随机数的函数 random.random() 生成一个0到1之间的随机小数
print(random.random())  # 生成一个0到1之间的随机小数

# 时间模块 time 获取当前时间
import time

# 获取当前时间的函数 time.time() 返回当前时间的时间戳：1970年1月1日0时0分0秒到现在的秒数
print(time.time())
# 获取当前时间的函数 time.localtime() 返回当前时间的时间元组
print(time.localtime())
# 获取当前时间的函数 time.asctime() 返回当前时间的字符串
print(time.asctime())
# 获取当前时间的函数 time.strftime(格式, 时间元组) 返回当前时间的格式化字符串
print(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))

# 数学模块 math 提供了数学运算的函数
import math

# 求平方根的函数 math.sqrt(x) 返回x的平方根
a = 4
print(math.sqrt(a))  # 2.0
# 求e的x次方的函数 math.exp(x) 返回e的x次方
a = 1
print(math.exp(a))  # 2.718281828459045
# 求对数的函数 math.log(x, y) 返回x的y底的对数
a = 2
print(math.log(a, 10))  # 0.30102999566398114
# 常量
print(math.pi)  # 圆周率
print(math.e)  # 自然对数的底

# 操作系统模块 os 提供了操作系统相关的函数 os：operation system
import os

# 获取当前目录的函数 os.getcwd() 返回当前目录的路径
print(os.getcwd())
# 获取当前目录的函数 os.listdir() 返回当前目录的文件列表
print(os.listdir())

# 系统模块 sys 提供了系统相关的函数 sys：system
import sys

# 获取系统版本的函数 sys.version 返回系统的版本信息
print(sys.version)
# 获取系统路径的函数 sys.path 返回系统的路径
print(sys.path)

# 日期时间模块 datetime 提供了日期时间相关的函数
import datetime

# 获取当前日期时间的函数 datetime.datetime.now() 返回当前日期时间
print(datetime.datetime.now())

# 机器学习深度学习：
# numpy 数值计算库
# pandas 数据处理库
# matplotlib 数据可视化库
# pytorch 深度学习库
# tensorflow 深度学习库
# sklearn 机器学习库
# ...


# 模块的调用方式
# 1. import 模块名         导入整个模块，用【模块名.函数名】的方式调用模块中的函数
# 2. from 模块名 import 函数名      导入模块中的一个函数，直接使用函数名调用函数
from math import sqrt, exp, pi, log #导入多个函数，用逗号分隔

print(sqrt(4))  # 2.0
# 3. from 模块名 import *          导入模块中的所有函数，直接使用函数名调用函数
from math import *

print(exp(1))  # 2.718281828459045
print(pi)

# 具体的好处：
# 1. 代码更加简洁
# 2. 不需要使用【模块名.函数名】的方式调用函数
# 3. 可以避免函数名重名的问题

# 可以给模块起别名
import math as m  # 给math模块起别名m

print(m.sqrt(4))  # 2.0
