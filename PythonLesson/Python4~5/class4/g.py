for i in range(0, 19):
    for f in range(0, 19 - i):
        #  i 蜘蛛 8 0
        #  f 蜻蜓 6 2
        #  18-i-f 蝉 6 1
        #  118 and 18
        if (8 * i + 6 * f + 6 * (18 - i - f)) == 118 and (2 * f + 1 *
                                                          (18 - i - f)) == 18:
            print(i)
            print(f)
            print(18 - i - f)

        # if i * 8 + (18 - i - i) * (10 - i) * 4 == 118:
        #     print(i)
        #     print(10-i)
        #     print(10-i)
a = 1
z = 0
while a <= 99:
    z += a
    a += 1
print(z)

z = 0
for i in range(1, 100):
    z += i
print(z)
