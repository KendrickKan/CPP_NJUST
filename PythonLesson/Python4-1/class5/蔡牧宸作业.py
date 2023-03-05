p=float(input(""))
if p%4<0 or p%400<0:
    print("不是")
else:
    print("是")
sum = 0
for i in range(1,101,3):
    sum =sum+ i
print(sum)
print(10*9*8*7*6*5*4*3*2*1)
