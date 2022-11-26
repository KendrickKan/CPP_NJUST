def myeee(a,b):
        return a+b
print(myeee(2,7))


def myc(d,g):
        return (d*g)/2
print(float(myc(2.5,6)))


def gtf(d,p):
        return d*d*p
print(float(gtf(7,3.1415926)))


def rty(a):
        g=1
        for i in range(1,a):
                if i % 2 == 0:
                        g+=i
        if a % 2 == 0:
                g = g + a
        return g-1
print(rty(20))