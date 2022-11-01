# 计算机 固定是拳头
# 人需要输入 拳头 布 剪刀
# 输出 人输 人赢 平局
# n = input('请出拳(拳头/剪刀/布): ')
# if n == '拳头':
#     print('平局')
# elif n == '剪刀':
#     print('你输了')
# elif n == '布':
#     print('你赢了')
# sum = 0
# for i in range(1, 100, 3):
#     sum = sum + i
# print(sum)
# 求 1 + 4 + 7 + ... <100 的和

# sum = 0
# i = 1
# while i <= 100:
#     sum = sum + i
#     i = i + 2
# print(sum)
# 1 + 3 + 5 ++++<=100 的和

sum = 0
for i in range(1, 100, 3):
    sum = sum + 1
    i = i + 1
print(sum)
