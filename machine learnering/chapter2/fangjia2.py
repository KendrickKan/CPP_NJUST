import numpy as np

# 加载数据
def load_data():
    X = np.array([
        [1, 2000], [1, 2001], [1, 2002], [1, 2003], [1, 2004], [1, 2005], [1, 2006], [1, 2007], [1, 2008], [1, 2009], [1, 2010], [1, 2011], [1, 2012], [1, 2013]
    ])
    Y = np.array([
        [2.000], [2.500], [2.900], [3.147], [4.515], [4.903], [5.365], [5.704], [6.853], [7.971], [8.561], [10.000], [11.280], [12.900]
    ])
    return X, Y

# 求闭式解
def close_form(X, Y):
    theta = np.linalg.inv(X.T@X)@X.T@Y
    print('theta0:')
    theta0 = theta[0][0]
    print(theta0)
    print('theta1:')
    theta1 = theta[1][0]
    print(theta1)
    print("y = " + str(theta1) +"*X" + str(theta0))
    # 预测2014年
    print("the housing price in 2014 is %f"%(2014 * theta1 + theta0))

def gradient_descent(X, Y, learn_rate = 0.2):
    theta0, theta1 = 0, 0
    loss, temploss = 1, 0
    lenth = len(X)

    # 均值方差归一化
    mean = np.mean(X,axis=0)
    variance = np.std(X,axis=0)
    X = (X - mean[1])/variance[1]

    # 梯度下降，以loss变化小于1e-10为迭代停止条件
    while abs(loss-temploss)>1e-8:
        temploss = loss
        loss=0
        gradient0, gradient1 = 0, 0
        # 计算梯度
        for i in range(lenth):
            gradient0 += theta0 + theta1 * X[i][1] - Y[i][0]
            gradient1 += (theta0 + theta1 * X[i][1] - Y[i][0]) * X[i][1]
        # 参数更新
        theta0 = theta0 - learn_rate * gradient0
        theta1 = theta1 - learn_rate * gradient1
        # 动态学习率
        learn_rate = learn_rate * 0.99
        # 计算损失
        for i in range(lenth):
            loss += (theta0 + theta1 * X[i][1] - Y[i][0]) ** 2

    # 预测2014年
    # x = (2014- mean[1])/variance[1]
    print('theta0:')
    theta0 = mean[1] / variance[1] * theta1 * -1 + theta0
    print(theta0)
    print('theta1:')
    theta1 = 1 / variance[1] * theta1
    print(theta1)
    print("y = " + str(theta1) +"*X" + str(theta0))
    print("the housing price in 2014 is %f"%(2014 * theta1 + theta0))


if __name__ == "__main__":
    X, Y = load_data()
    print("\n使用LMS闭式解：")
    close_form(X, Y)
    print("\n使用梯度下降算法：")
    gradient_descent(X, Y)
