# 面向对象的编程语言
# C语言是面向过程的编程语言：按照流程来编写代码
# 面向对象的编程语言：按照对象来编写代码
# c++、java、python都是面向对象的编程语言

# 对象：对象是类的实例，是一个具体的事物
# 类：类是对象的抽象，是一个模板，定义了对象的属性和行为

# 具体的例子来理解面向对象的编程语言
# 具体的一个人：对象：张三、李四、王五，实例化了一个人

# 人：类：定义了人的属性和行为
# 属性：姓名、年龄、性别
# 行为：吃饭、睡觉、工作

# 面向对象的编程：在编程的时候，首先考虑的是对象，然后考虑对象的属性和行为
# 类和对象的关系：类是对象的抽象，对象是类的实例
# 之前在Python里，我们已经接触了很多类，比如列表、元组、字典
# 列表、元组、字典都是类，是Python内置的类
list1 = [1, 2, 3, 4, 5]  # 创建了一个列表对象
list1.append(6)  # 调用了列表对象的append方法


# 类和对象 和 c语言中的结构体类似 结构体里面只有属性 没有方法（函数）
# 类里面有属性和方法
# 结构体是用struct关键字定义 结构体名字
# 结构体定义
# struct 结构体名字{
#     属性
# };


# class关键字定义类 python和c++都有类
# 类里面有属性和方法：属性是类的特征，方法是类的行为
# 类定义
# class 类名:
#     属性
#     方法
class Student:
    # 定义类的属性
    # 可以省略，不建议省略
    # name = ""
    # number = 0
    # grade = 0
    __age = 0

    # 特别的方法：构造函数
    # 构造函数是类的特殊方法，用来初始化对象
    def __init__(self, name, number, grade):
        print("create student")
        # self 就会用到了
        self.name = name
        self.number = number
        self.grade = grade
        self.__age = 18  # 定义了一个私有属性
        # self 代表的是类的实例（对象），而不是类本身
        # 如果在外面没有定义属性，可以在构造函数里面定义属性
        # self.name = name 定义了一个属性，属性的值是name

    # 定义类的方法（函数）
    # 定义方法的时候，第一个参数是self，self代表类的实例
    def eat(self):
        print("eat")

    def getAge(self):
        self.__sleep()
        return self.__age

    # 私有方法
    def __sleep(self):
        print("sleep")


# 结构体创建实例化
# struct 结构体名字 结构体变量名字 = {属性值};

# 类的实例化，创建一个类的对象
# 类名() 创建一个类的对象 构造函数
# 在定义类的时候，自动定义了一个构造函数
# stu1 = Student()  # 创建了一个学生对象 自动调用init方法
stu1 = Student("zhangsan", 1001, 90)  # 创建了一个学生对象 自动调用init方法
# self 就是代表的stu1
print(stu1.name)  # 访问对象的属性
stu1.eat()  # 调用对象的方法

# 类有 公有属性 私有属性
# 公有属性：在类的外部可以访问
# 普通定义就行
# 私有属性：在类的外部不能访问
# 在属性前面加上两个下划线 __
# print(stu1.__age)  # 不能访问私有属性
print(stu1.getAge())  # 通过方法访问私有属性
# 私有属性的用处：保护属性，防止外部直接访问属性


# stu1.__sleep()  # 不能调用私有方法s


# 类的继承
# 如果一种面向对象的编程语言不支持继承，类就是没有什么意义的
# 继承是面向对象的三大特性之一：封装、继承、多态
# 继承：类的一些属性和方法可以被其他类继承
# 不同的类之间有共通性，但是又有一些不同的地方
# 就可以把共通的部分抽象出来，放到一个父类里面
# 然后其他类【继承】这个父类，就可以使用父类的属性和方法


# 定义一个中学生类，继承学生类
class MiddleStudent(Student):  # 继承Student类
    def __init__(self, name, number, grade, middleGrade):
        # 调用父类的构造
        # super() 函数是用于调用父类(超类)的一个方法
        super().__init__(name, number, grade)
        self.middleGrade = middleGrade

    # 重写父类的方法：在调用的时候，调用子类的方法，不再调用父类的方法
    def eat(self):
        print("middle eat")

    def printInfo(self):
        print(self.name, self.number, self.grade, self.middleGrade)

# MiddleStudent 的属性 = Student的属性 + MiddleStudent的属性
# MiddleStudent 的方法 = Student的方法 + MiddleStudent的方法


midstu1 = MiddleStudent("lisi", 1002, 80, 70)
midstu1.eat()  # 调用父类的方法
# midstu1.__init__("lisi", 1002, 80, 60)  # 调用父类的方法
# __init__ 是构造函数，不是方法

# 先从子类找方法，如果子类没有，再从父类找方法

# 类继承的好处：代码的复用，减少代码的重复编写

# 多态：同一个方法，不同的对象调用，产生不同的结果
midstu2 = MiddleStudent("wangwu", 1003, 90, 80)
midstu1.printInfo()
midstu2.printInfo()

# 多态的好处：提高代码的灵活性，减少代码的耦合度

# 对于python来说，创建的变量 其实就是对象
list1 = [1, 2, 3, 4, 5]
# list1 是一个列表对象
# list1.__len__  # 调用列表对象的append方法
# append方法是列表类里面定义好了的

# __init__ 是构造函数，python里面的构造函数是特殊的方法
# __init__ 方法是在创建对象的时候自动调用的
# 对于python自动创建自动运行的代码，我们称之为魔术方法