import numpy as np

if __name__ == '__main__':
    # LMS method  闭式解求线性回归
    X = np.array([
        [1, 2000], [1, 2001], [1, 2002], [1, 2003], [1, 2004], [1, 2005], [1, 2006], [1, 2007], [1, 2008], [1, 2009], [1, 2010], [1, 2011], [1, 2012], [1, 2013]
    ])
    Y = np.array([
        [2.000], [2.500], [2.900], [3.147], [4.515], [4.903], [5.365], [5.704], [6.853], [7.971], [8.561], [10.000], [11.280], [12.900]
    ])
    XT = np.transpose(X)   # X matrix 转置
    RESULT1 = np.linalg.inv(XT@X)@XT@Y  # LMS闭式解

    # Gradient Descent 梯度下降求逻辑回归
    # 迭代阀值，当两次迭代损失函数之差小于该阀值时停止迭代
    epsilon = 0.0000001
    # 学习率
    alpha = 0.0000000354
    diff = [0, 0]
    error1 = 0
    error0 = 0
    counter = 0   # 优化次数迭代器
    m = len(X)
    # 初始化参数
    theta0 = -1580
    theta1 = 0.8
    while True:
        counter += 1
        a0 = theta0
        a1 = theta1
        # 参数迭代计算
        for i in range(m):
            # 拟合函数为 y = theta0 * x[0] + theta1 * x[1]
            # 计算残差
            diff[0] = (a0 + a1 * X[i][1]) - Y[i][0]
            # 梯度 = diff * x[i][j]
            theta0 -= alpha * diff[0]*1000
            theta1 -= alpha * diff[0] * X[i][1]

        # 计算损失函数
        error1 = 0
        for lp in range(m):
            error1 += (Y[lp][0] - (theta0 + theta1 * X[lp][1])) / 14
        if abs(error1 - error0) < epsilon:
            break
        else:
            error0 = error1
        print('No.%d: theta0 : %f, theta1 : %f, error1 : %f' % (counter,theta0, theta1, error1))

    print("              拟合结果如下")
    print("LMS method :")
    print(" y = " + str(RESULT1[1][0])+"x" + str(RESULT1[0][0]))
    print("预估2014年南京的平均房价为 : "+str(RESULT1[1][0]*2014+RESULT1[0][0]))
    print("GD method :")
    print(" y = " + str(theta1) + "x" + str(theta0))
    print("预估2014年南京的平均房价为 : " + str(theta1 * 2014 + theta0))


