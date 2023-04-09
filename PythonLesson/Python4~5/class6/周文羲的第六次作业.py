t = (2,)
print(t)



t = (1,2,3,4,5)
print(type(t))
for i in range( len (t)):
    print(t[i])
for i in t :
    print(i)
print(t[0])
print(t[4])
print(t * 2)



s1 = set()
s2 = set()
print(type(s1))
print(type(s2))
s1.update({1,3,'A','B'})
s2.update({'D','A',1,4})
print(type(s1))
print(type(s2))
print(s1|s2)
print(s1&s2)
print(s1-s2)
print(s1^s2)
s1.remove('A')
s2.pop