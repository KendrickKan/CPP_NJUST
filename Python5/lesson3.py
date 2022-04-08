basket = {'apple','orange','apple','pear','banana'}
print(basket)
basket2 = set()#创建空的
print(basket2)
print('orange' in basket)#True
print('watermelon' in basket)#False
#set可以创建非空的集合
basket3 = set('acaabcde')
print(basket3)
###########集合运算
A = set('1357')
B = {'2','4','5','6','8'}
print(A|B)#1 2 3 4 5 6 7 8
print(A-B)#1 3 7
print(B-A)#2 4 6 8
print(A&B)#5
print(A^B)#1 3 7 2 4 6 8

S = {'1','2','3'}
S2 = {'4','5'}
#S.add('4')
#S.update(S2)
#S.update({'4','5'})
#S.add('1')
#S.remove('2')
#S.remove('4')#报错
#S.discard('2')
#S.discard('4')#不会报错
#S.pop()#随机删除
print(S)

SS = {'A','B','1','2'}
print(len(SS))
SS.clear()
print(SS)
SS = {'A','B','1','2'}
print('B' in SS)#True
print('5' in SS)#False