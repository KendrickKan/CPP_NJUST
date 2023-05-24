s='hello Word! 我 爱 编程'
zm = 0
kg = 0
qt = 0
for i in s:
    if i.isspace():
        kg += 1
    elif i.isalpha():
        zm += 1
    else:
        qt += 1
print('zm={}kg={}qt={}'.format(zm,kg,qt))