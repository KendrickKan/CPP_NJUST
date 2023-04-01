N = input()
n = int(N)
a = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
offset = 1
for c in N:
    t = int(c)
    high = int(n / (10 * offset))
    low = int(n % offset)
    if t == 0:
        a[0] += (high - 1) * offset + low + 1
        for i in range(1, 10):
            a[i] += high * offset
    else:
        for i in range(10):
            if i < t and i != 0:
                a[i] += (high + 1) * offset
            elif i == t:
                a[i] += high * offset + low + 1
            elif i > t or i == 0:
                a[i] += high * offset
    offset *= 10

for i in range(10):
    print(i, a[i])