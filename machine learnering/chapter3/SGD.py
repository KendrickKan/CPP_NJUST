from numpy import *
import matplotlib.pyplot as plt
import random
from matplotlib.pyplot import MultipleLocator
import warnings


def normalization(x):
    mu = mean(x, axis=0)
    sigma = std(x, axis=0)
    return (x - mu) / sigma


def loadDataSet():
    f = open('D:/VSCode File/CPlusPlus/machine learnering/chapter3/ex4x.dat')
    data = []
    for line in f:
        lineArr = line.strip().split()
        data.append([float(lineArr[0]), float(lineArr[1])])
    f.close()
    f = open('D:/VSCode File/CPlusPlus/machine learnering/chapter3/ex4y.dat')
    label = []
    for line in f:
        lineArr = line.strip().split()
        label.append(int(float(lineArr[0])))
    f.close()
    # data归一化 添加1
    data = normalization(data)
    data1 = []
    for i in data:
        data1.append([1, i[0], i[1]])
    return data1, label


def sigmoid(z):
	g = 1 / (1 + exp(-z))
	return g


def stocGradDescent(data, label):
    dataMat = mat(data)
    labelMat = mat(label).transpose()
    n, m = shape(dataMat)  # n samples, m features
    theta = mat([[1], [-1], [1]])

    alpha = 0.001
    maxCycle = 500
    episilon = 0.1
    h = sigmoid(dataMat * theta)
    error = h - labelMat
    precost = (-1) * (labelMat.transpose() * log(h) + (ones(
        (n, 1)) - labelMat).transpose() * log(ones((n, 1)) - h))
    plt.ion()
    xs = [0, 0]
    ys = [0, precost[0, 0]]

    for k in range(maxCycle):
        arr = list(range(n))
        while len(arr):
            rand = random.randint(0, len(arr) - 1)
            arr.pop(rand)
            # choose only one sample
            theta = theta + alpha * ((-error[rand][0, 0]) * dataMat[rand].transpose())
            h = sigmoid(dataMat * theta)
            error = h - labelMat
        cost = (-1) * (labelMat.transpose() * log(h) + (ones(
            (n, 1)) - labelMat).transpose() * log(ones((n, 1)) - h))
        xs[0] = xs[1]
        ys[0] = ys[1]
        xs[1] = k + 1
        ys[1] = cost[0, 0]
        fig = plt.figure(1)
        with warnings.catch_warnings():
            warnings.simplefilter("ignore")
            ax = plt.subplot(121)
        ax.set_title("cost", fontsize=8)
        ax.plot(xs, ys)
        plotResult(data, label, theta, fig)
        plt.pause(0.001)
        if abs(precost - cost) < episilon:
            break
    print(k)
    return theta


def plotResult(data, label, theta, fig):
    dataMat = mat(data)
    labelMat = mat(label).transpose()
    xcord1 = []
    ycord1 = []
    xcord0 = []
    ycord0 = []
    for i in range(shape(data)[0]):
        if (label[i]) == 0:
            xcord0.append(dataMat[i, 1])
            ycord0.append(dataMat[i, 2])
        else:
            xcord1.append(dataMat[i, 1])
            ycord1.append(dataMat[i, 2])
    with warnings.catch_warnings():
        warnings.simplefilter("ignore")
        ax = plt.subplot(122)
    plt.cla()
    ax.scatter(xcord0, ycord0, s=30, c='red', marker='s')
    ax.scatter(xcord1, ycord1, s=30, c='green')
    x_major_locator = MultipleLocator(1)
    y_major_locator = MultipleLocator(2)
    ax.xaxis.set_major_locator(x_major_locator)
    ax.yaxis.set_major_locator(y_major_locator)
    plt.xlim(-3, 3)
    plt.ylim(-3, 3)
    x = arange(-3, 3, 0.1)
    y = (-theta[1, 0] * x - theta[0, 0]) / theta[2, 0]
    ax.plot(x, y)


def main():
    data1, label = loadDataSet()
    theta = stocGradDescent(data1, label)
    print(theta)
    plt.ioff()
    plt.show()


if __name__ == '__main__':
    main()
