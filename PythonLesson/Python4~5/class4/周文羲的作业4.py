for i in range (0,19) :
    for f in range (0,19 - i ) :
        if i * 8 + (18 - i - i) * (10 - i) * 4 == 118:
            print('the number of {} is {}'.format('spider',i))
            print('the number of {} is {}'.format('cicada',10-i))
            print('the number of {} is {}'.format('dragonflydog',10-i))






# i=蜘蛛 ; 蜘蛛有 8 条腿，蜻蜓有 6 条腿和 2 对翅膀，蝉有 6 条腿和 1
# 对翅膀，现在这三种小虫共 18 只，有 118 条腿和 18 对翅膀，蜘蛛、
# 蜻蜓、蝉各几只? 、
a=1
z=0
while a <= 100 :
    z += i
    i += 1
print(z)

    

# 使用 for 循环和 while 循环计算 1-99 的和