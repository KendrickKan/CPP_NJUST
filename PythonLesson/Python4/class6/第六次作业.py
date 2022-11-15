num=[];
i=2
for i in range(2,100):
   j=2
   for j in range(2,i):
      if(i%j==0):
         break
   else:
      num.append(i)
print(num)




for i in range(1,10):
    for j in range(1,10):
        print('{}*{}={:<5d}'.format(i,j,i*j),end='')
    print()
