import time


def Sum(n):
    if (n == 1):
        return 1
    return n + Sum(n - 1)


start_time = time.time()
print(Sum(100000))
end_time = time.time()
run_time = end_time - start_time
print(run_time)