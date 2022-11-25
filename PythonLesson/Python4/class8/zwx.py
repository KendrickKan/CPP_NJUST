sum=0
i=2
while i <=100:
    sum+=i
    i+=2
print(sum)






# sum=0
for i in range(1,1001):
    if not(i%3==0 and i%8==0):
        continue
    print(i)





i=int(input('请输入一个整数:'))
for j in range(1,i):
    if(i%j==0):
        print(j,end='')




