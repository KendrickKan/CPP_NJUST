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
for i in range(len(str)):  # 0 1 2 3 4 5 6 7 8
    print(str[i], end=' ')

#用for循环求100以内的素数
for i in range(2, 101):
    flag = False  #定义一个旗帜（标志bool类型），默认为False，用于判断i是否为素数
    for j in range(2, i):
        if i % j == 0:
            flag = True  #如果i能被j整除，说明i不是素数，将旗帜置为True
    if flag == False:  #如果旗帜为False，说明i是素数
        print(i)

a = 1
b = True
print(0.1 + 0.2)
print(0.1 + 0.2 == 0.3)
