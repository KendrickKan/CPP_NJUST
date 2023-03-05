sum=0
for i in range(1,100,3):
    sum=sum+i    
print(sum)



i=1
result=0
while i < 101:
    result += i
    i +=3
print(result)
print(i)




i=1
result=1
while i <=10:
    result *= i # result = result * i
    i +=1 # i = i + 1
print(result)


sum=1
for i in range(1,11):
    sum=sum*i
print(sum)


while True:
    ryy=int(input('请输入年份：'))
    print(ryy)
    if  ryy%4==0 and ryy%100!=0 or ryy%400==0:
        print('闰年')
    else:
        print('不是闰年')

    

 
 
