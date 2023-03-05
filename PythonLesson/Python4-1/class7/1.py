p=2
while p<=100:
    j=2
    flag = False
    while j<p:
        if(p%j==0):
            flag = True
    else:
        if flag == False:
            print(p,end=' ')
    p+=1
i=1
while i <=9:
    j=1
    while j <= i:
        print(i,end='*')
        print(j,end='=')
        print(i*j,end=' ')
        j+=1
    i+=1
    print('')
