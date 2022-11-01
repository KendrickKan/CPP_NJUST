# letters = 0
# space = 0
# digit = 0
# others = 0

# def counts(str):
#     global letters
#     global space
#     global digit
#     global others
#     for i in range(0, len(str)):
#         if (str[i] >= '0' and str[i] <= '9'):
#             digit += 1
#         elif ((str[i] >= 'a' and str[i] <= 'z')
#               or (str[i] >= 'A' and str[i] <= 'Z')):
#             letters += 1
#         elif (str[i] == ' '):
#             space += 1
#         else:
#             others += 1

# s='hello Word! 我 爱 编程'
# counts(s)
# print(letters)
# print(space)
# print(digit)
# print(others)

# a = 0  #字母个数
# b = 0  #空格个数
# c = 0  #数字个数
# d = 0  #其他个数
# def jishu(s):
#     global a, b, c, d  #global 全局变量
#     for i in range(0, len(s)):
#         if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z')):
#             a = a + 1
#         elif (s[i] >= '0' and s[i] <= '9'):
#             c = c + 1
#         elif (s[i] == ' '):
#             b = b + 1
#         else:
#             d = d + 1
# s = 'hello Word! 我 爱 编程'
# jishu(s)
# print(a)
# print(b)
# print(c)
# print(d)

# s1 = "1"
# s2 = "0"
# s3 = ""  #空字符串就是False
# print(bool(s1))
# print(bool(s2))
# print(bool(s3))
# print(bool(False))

# def mianji(a, b, c):
#     d = (a + b) * c / 2
#     return d

# a = int(input())
# b = int(input())
# c = int(input())
# d = mianji(a, b, c)
# print(d)
import random  #导入随机库

a = random.randint(1, 3)  #玩家
b = random.randint(1, 3)  #机器

