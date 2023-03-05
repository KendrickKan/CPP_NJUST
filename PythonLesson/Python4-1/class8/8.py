# a = 1
# b = 2
# c = a\
# +b
# print(c)
# for str in "Python":
#     if str == 'h':
#         break
#     print(str)
# for str in "Python":
#     if str == 'h':
#         continue
#     print(str)
# a = 5
# print(a/2)
# print(7-a)
# print(a%3)
# print(a*(-1)+7)

# 求1-100之间的偶数和
sum = 0
for i in range(2, 101, 2):
    sum += i
print(sum)

# 求输入整数的所有因子
i = int(input("请输入一个整数："))
j = 1
while j <= i:
    if (i % j == 0):
        print(j, end=' ')
    j += 1
