import time


def Sum(n):
    ans = 0
    for i in range(n + 1):
        ans += i
    return ans


start_time = time.time()
print(Sum(100000))
end_time = time.time()
run_time = end_time - start_time
print(run_time)