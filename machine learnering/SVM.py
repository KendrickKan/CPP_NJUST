import numpy as np
import random
import torch
from libsvm.commonutil import svm_read_problem
from libsvm.svmutil import *
from libsvm.svm import *
X=np.loadtxt('C:/Users/21/桌面/ex4Data/ex4x.dat')
Y=np.loadtxt('C:/Users/21/桌面/ex4Data/ex4y.dat')
X=np.insert(X,0,values=Y,axis=1)

#预处理数据集，打乱，以进行5倍交叉验证
np.random.shuffle(X)#注意不能用random.shuffle
Y_total=X[:,0]
X_total=np.delete(X,0,axis=1)
acc_test=0            #测试样本平均正确率
acc_train=0           #训练样本平均正确率

#k-fold 5倍交叉验证 每次取打乱的数据中一份
print('Logistic(SGD) 5倍交叉验证比较')
for k in range(5):
    #训练集
    X=X_total
    Y=Y_total
    offset = int(len(X_total) / 5)
    X = np.delete(X, slice(k * offset, k * offset + offset), axis=0)    #删除1/5训练集作为测试集
    Y = np.delete(Y, slice(k * offset, k * offset + offset), axis=0)
    #测试集
    X_test = X_total
    Y_test = Y_total
    X_test=X_test[k*offset:k * offset + offset]
    Y_test=Y_test[k*offset:k * offset + offset]
    print('交叉验证k-fold：'+str(k+1))

    # 归一化处理
    X_mean = np.mean(X, 0)                       #压缩行，对列求均值
    X_std = np.std(X, 0)                         #标准差
    X_scale = (X - X_mean) / X_std

    X = np.append(np.ones((len(X), 1)), X, 1)                     #统计X个数放在第二列
    X_scale = np.append(np.ones((len(X_scale), 1)), X_scale, 1)


    def sigmoid(z):
        return 1.0 / (1.0 + np.exp(-1.0 * z))


    # Logistic SDG    逻辑回归（随机梯度下降）
    def stochastic_gradient_descent(x_arr, y_arr, theta, alpha):
        theta_new = theta.copy()
        # 随机取样本
        i = random.randint(0, x_arr.shape[0] - 1)     #随机闭区间
        j = random.randint(0, x_arr.shape[1] - 1)
        sum_err = 0.0
        sum_err += (sigmoid((np.matrix(theta) * np.matrix(x_arr[i]).T).item(0, 0)) - y_arr[i]) * x_arr[i, j] #损失函数
        theta_new[j] = theta[j] - alpha * sum_err / x_arr.shape[0]   #alpha学习率   theta最大似然估计量

        return theta_new


    alpha = 12
    thetas_gd = np.array([0.0, 0.0, 0.0])  # 初始参数
    err_gd_list = [0.0] * 300  # 统计误差
    for j in range(300):
        err_gd = 0
        for i in range(X.shape[0]):
            err_gd += np.log(sigmoid((np.matrix(thetas_gd) * np.matrix(X_scale[i]).T).item(0, 0))) * Y[i] + np.log(
                1 - sigmoid((np.matrix(thetas_gd) * np.matrix(X_scale[i]).T).item(0, 0))) * (1 - Y[i])
        err_gd = -err_gd / X.shape[0]
        err_gd_list[j] = err_gd
        # 随机梯度下降迭代求解参数
        thetas_gd = stochastic_gradient_descent(X_scale, Y, thetas_gd, alpha)

    # 梯度下降用测试集验证正确率
    # 这里不绘制结果
    # 梯度下降的结果绘制，注意对归一化的值进行反处理
    # for k in range(len(X)):
    #     if (Y[k] > 0):
    #         plt.scatter(X[k][1], X[k][2], marker='+', color='red')
    #     else:
    #         plt.scatter(X[k][1], X[k][2], color='blue')
    # plt.title('SVM vs.Logistic vs.ANN')
    #
    # x1_gd = list(range(0, 70))
    # x2_gd = -1.0 * (thetas_gd[0] + thetas_gd[1] * ((np.array(x1_gd) - X_mean[0]) / X_std[0])) / thetas_gd[2]
    # x2_gd = np.array(x2_gd) * X_std[1] + X_mean[1]
    # print(x1_gd,x2_gd)
    #
    # plt.plot(x1_gd, x2_gd, label='Logistic(SGD)')
    # plt.axis([0, 70, 30, 90])
    # plt.legend()
    # plt.show()
    right = 0
    for i in range(len(X)):
        x1 = X[i][1]
        x2 = X[i][2]
        x2_forcast = -1.0 * (thetas_gd[0] + thetas_gd[1] * ((x1 - X_mean[0]) / X_std[0])) / thetas_gd[2]
        x2_forcast = x2_forcast * X_std[1] + X_mean[1]
        if x2_forcast <= x2 and Y[i] > 0:
            right += 1
        elif x2_forcast > x2 and Y[i] <= 0:
            right += 1
    acc = right / len(X)
    acc_train += right / len(X)
    print('训练样本acc=' + str(acc),end=' ')

    right=0
    for i in range(len(X_test)):
        x1 = X_test[i][0]
        x2 = X_test[i][1]
        x2_forcast = -1.0 * (thetas_gd[0] + thetas_gd[1] * ((x1 - X_mean[0]) / X_std[0])) / thetas_gd[2]
        x2_forcast = x2_forcast * X_std[1] + X_mean[1]
        if x2_forcast<=x2 and Y_test[i]>0:
            right+=1
        elif x2_forcast>x2 and Y_test[i]<=0:
            right+=1
    acc=right/len(X_test)
    acc_test+=right/len(X_test)
    print('测试样本acc='+str(acc))

print('logistic(SGD)最终结果：训练样本acc：'+str(acc_train/5)+' 测试样本acc: '+str(acc_test/5))
print('--------------------------------------')

#ANN 三层前馈神经网络
print('ANN（隐层单元10个，训练500次）结果如下：')
HIDDEN_SIZE = 10     #隐层单元数 （隐藏的神经节点）         输入层  隐藏层  输出层

X=np.loadtxt('C:/Users/21/桌面/ex4Data/ex4x.dat')             #读取位于该位置的文件
Y=np.loadtxt('C:/Users/21/桌面/ex4Data/ex4y.dat').astype(int)


class ANN(torch.nn.Module):       #继承torch 神经网络模块基类
    #初始化
    def __init__(self, input_size, hidden_size, output_classes):
        super(ANN, self).__init__()
        #三层网络 输入层、隐层、输出层
        self.input_size = input_size
        self.hidden_size = hidden_size
        self.output_classes = output_classes
        # 归一化
        self.bn1 = torch.nn.BatchNorm1d(input_size)    #激活函数前进行归一，否则已学习好的特征被归一了
        # 设置网络中的全连接层
        self.fc1 = torch.nn.Linear(input_size, hidden_size)     #全连接层fc1 输入层 —— 隐藏层
        self.fc2 = torch.nn.Linear(hidden_size, output_classes) #全连接层fc2 隐藏层 —— 输出层
    #传播函数
    def forward(self, X):           #按步骤进行归一，连接隐藏层，前馈，连接输出层，前馈
        X = self.bn1(X)
        X = self.fc1(X)
        X = torch.sigmoid(X)    #将值映射到0和1之间
        X = self.fc2(X)
        X = torch.sigmoid(X)
        return X                    #得到输出层数据

#独热编码转换        # 损失函数MSELoss需要           
def one_hot(y_origin):
    """
    标签转换成独热编码
    [0, 1] -> [[1, 0], [0, 1]].
    """
    y_now = np.zeros((y_origin.size, 2), dtype=int)
    y_now[np.arange(y_origin.size), y_origin.flatten()] = 1
    return y_now

#计算准确率
def acc(train_x, train_y, test_x, test_y):
    #调用Tensor类的构造函数__init__，生成单精度浮点类型的张量
    #首先计算训练样本
    x = torch.Tensor(train_x)      # torch.FloatTensor 类型张量
    y = torch.Tensor(train_y)
    pred = model(x)               # 使用x创建ANN类
    pred = torch.argmax(pred, dim=-1)   #dim对应维度， argmax取得最大值的索引
    y = torch.argmax(y, dim=-1)
    pred = pred.numpy()#将Tensor变量转化为ndaray
    y = y.numpy()
    acc_train = np.sum(pred == y) / pred.shape[0]

    #再用测试样本计算
    x = torch.Tensor(test_x)  #调用Tensor类的构造函数__init__，生成单精度浮点类型的张量
    y = torch.Tensor(test_y)
    pred = model(x)
    pred = torch.argmax(pred, dim=-1)
    y = torch.argmax(y, dim=-1)
    pred = pred.numpy()
    num=pred.shape[0]
    y = y.numpy()
    acc_test = np.sum(pred == y) / num
    return acc_train, acc_test

def k_fold(len, fold=5):
    #5倍交叉验证
    total = np.arange(len, dtype=int) #默认步长为1
    for f in range(fold):
        test = np.arange(f, len, fold, dtype=int)#从f开始，步长为5
        train = np.setdiff1d(total, test) #total与test差集为train
        yield (f+1, train, test)    # 迭代器——与return不同，函数返回某个值时，会停留在某个位置，返回函数值后，会在前面停留的位置继续执行直到程序结束

x = np.array(X)
y = np.array(Y)
MES_loss = torch.nn.MSELoss()
x_dim = x.shape[1]#多少列
length = x.shape[0]#多少行
output_classes = y.max() + 1#2
y = one_hot(y)

acc_train_total=0
acc_test_total=0
for (f, train, test) in k_fold(length, fold=5):
    print("交叉验证k-fold："+str(f))
    model = ANN(x_dim, HIDDEN_SIZE, output_classes)

    opt = torch.optim.Adam(model.parameters(), lr=0.1)#优化算法，学习率为0.1

    train_x, train_y = x[train], y[train]#k_fold（）选取训练集
    test_x, test_y = x[test], y[test]#k_fold（）选取测试集

    model.train()#启用batch normalization和drop out；model.train()是保证BN层能够用到每一批数据的均值和方差
    acc_train=0
    acc_test=0
    #训练500次
    for i in range(500):
        model.train()
        x1 = torch.Tensor(train_x)
        y1 = torch.Tensor(train_y)
        x1 = model(x1)
        opt.zero_grad()# 梯度值清零
        loss = MES_loss(x1, y1) #损失函数计算
        loss.backward()# 反向传播
        opt.step()#模型更新
        model.eval()#把BN和Dropout固定住，不会取平均，而是用训练好的值
        acc_train, acc_test = acc(train_x, train_y, test_x, test_y)
    acc_test_total+=acc_test
    acc_train_total+=acc_train
    print('训练样本acc: '+str(acc_train)+' 测试样本acc: '+str(acc_test))
print('ANN最终结果:训练样本acc: ' + str(acc_train_total/5) + ' 测试样本acc: ' + str(acc_test_total/5))

#SVM
#libsvm训练数据
print('--------------------------------------')
print('libsvm测试结果如下：')
y_svm_train, x_svm_train = svm_read_problem('C:/Users/21/桌面/ex4Data/train1.txt')#读取libsvm格式的文件，返回分类标签([])和数据([[]])
y_svm_test, x_svm_test = svm_read_problem('C:/Users/21/桌面/ex4Data/test1.txt')
model = svm_train(y_svm_train, x_svm_train,'-c 4 -t 0')#从样本数据中训练出用来判定的规则
                                                       #-c 4 设置从惩罚系数
                                                       #-t -0 设置核函数类型 线性核函数
#调节参数看不同结果
print('libsvm(参数C=4,选用线性核函数)结果如下：')
svm_predict(y_svm_test[0:], x_svm_test[0:], model)#根据训练获得的模型，对数据集合进行预测。
model = svm_train(y_svm_train, x_svm_train,'-c 1 -t 2')#从样本数据中训练出用来判定的规则
                                                       #-c 1 设置从惩罚系数
                                                       #-t 2 设置核函数类型 RBF核函数
print('libsvm(参数C=1,选用RBF径向基核函数)结果如下：')
svm_predict(y_svm_test[0:], x_svm_test[0:], model)#根据训练获得的模型，对数据集合进行预测。

input('按任意键继续')