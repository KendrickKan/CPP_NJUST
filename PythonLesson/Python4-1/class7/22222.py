i=1
while i<=9:
    j=1
    while j<=9:
        print(i,end='')
        print('*',end='')
        print(j,end='')
        print('=',end='')
        print(i*j,end=' ')
        j+=1
    i+=1
    print()



i=2
while i<=100:
    j=2
    while j<i:
        if(i%j==0):
            break
        j+=i
    else:
        print(i,end=' ')
    i+=1
