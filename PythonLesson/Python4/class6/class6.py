# a = 1
# b = 1
# c = a + b
# print(a)
# print(b)
# print(c)
# for i in range(98):
#     a = b
#     b = c
#     c = a + b
#     print(c)

# for a in range(1, 10):
#     for b in range(1, a + 1):
#         print(b, end="*")
#         print(a, end="=")
#         print(b * a, end=' ')
#     print()

str = 'abcdefghi'
# ch means char char就是一个字符
# for ch in str:
#     print(ch, end=' ')
len(str)  #str的长度:9
for i in range(len(str)): # 0 1 2 3 4 5 6 7 8
    print(str[i], end=' ')
