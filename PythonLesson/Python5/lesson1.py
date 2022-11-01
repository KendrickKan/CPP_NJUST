#函数复习

#a 起点 [1,2) >=1 <2 (1,2) (1,2] [a,b)
#b 终点
#c 每次走几步
#key  values
# a = {"first":1,"second":2,"third":3,"fourth":4,"fifth":5}

# b = [1,5,6,3,10,7]
# b.sort(reverse=True)#降序
# print(b)
# b.sort(reverse=False)#升序
# print(b)

# 编写一个函数 输入长方形的长和宽 输出面积
# chang=[5,9,10,6,8]
# kuan=[4,8,9,5,7]
# 输出上面两个列表的面积添加到一个新的列表里，输出列表
# 然后再升序，输出列表
# mianji={"first":1,"second":2,"third":3,"fourth":4,"fifth":5}
# 然后修改字典里的值,填入算出来升序了的面积，输出字典
# def area(a, b):
#     return a * b

# chang = [5, 9, 10, 6, 8]
# kuan = [4, 8, 9, 5, 7]
# areas = []
# for i in range(5):
#     c = area(chang[i], kuan[i])
#     areas.append(c)
# print(areas)
# areas.sort(reverse=False)#升序
# areas.sort(reverse=True)#降序
# print(areas)
# mianji = {"first": 1, "second": 2, "third": 3, "fourth": 4, "fifth": 5}
# mianji["first"] = areas[0]
# mianji["second"] = areas[1]
# mianji["third"] = areas[2]
# mianji["fourth"] = areas[3]
# mianji["fifth"] = areas[4]
# print(mianji)

#元组 tuple
a = (1, 2, 3, 4, 5)
#    0  1   2  3  4 
#  -5  -4  -3  -2  -1
b = ("A", )  #只有一个元素，后面要加上逗号
c = ()
#用正数下标和复数下标
print(a[2])#输出3
print(a[-3])
print(a[1:4])#输出2 3 4
print(a[-4:-1])
print(a[2:])#输出3后面
print(a[-3:])
d = a + b
print(d)
#删除d
del d
print(len(a))
print(max(a))
print(min(a))
print(3 in a)
print(0 in a)
print(a * 3)
# c=(2)
# print(type(c))#输出c的类型 int整型
# print(type(a))
#遍历元组a
for x in a:
    print(x) 
for x in range(len(a)): #for x in range(5): #x = 0 1 2 3 4
    print(a[x])


#创建一个fruit元组含有apple banana orange
#然后把他们复制5次输出
#然后用两种方法输出后面两个元素 