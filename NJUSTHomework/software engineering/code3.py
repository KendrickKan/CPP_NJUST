import time


def Sum(n):
    return (1 + n) * n / 2


start_time = time.time()
print(Sum(100000))
end_time = time.time()
run_time = end_time - start_time
print(run_time)