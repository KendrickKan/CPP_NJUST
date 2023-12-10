# import requests
# import time
# # import logging
# import winsound

# winsound.Beep(600, 1000)

# url = 'https://cd.jd.com/stocks?callback=jQuery6770117&type=getstocks&skuIds=100028068835%2C100028068843%2C100050087025&area=12_904_907_50559&_=1679997916768'
# flag = True

# while flag:
#     r = requests.get(url)
#     print(r.text)
#     print(r.text.find('现货'))
#     # logging.info(r.text)
#     # logging.info(r.text.find('现货'))
#     print(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())))
#     # logging.info(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())))
#     if (r.text.find('现货') != -1):
#         print('现货\n')
#         # logging.info('现货\n')
#         winsound.Beep(600, 1000000)

#         flag = False
#     else:
#         print('无货\n')
#         # logging.info('无货\n')

#     time.sleep(10)


def calculate_factorial(n):
    if n < 0:
        return "Invalid input, factorial is not defined for negative numbers."

    result = 1
    intermediate_result = 0

    for i in range(1, n + 1):
        intermediate_result += i
        result *= intermediate_result

    return result

def main():
    user_input = int(input("Enter a positive integer: "))
    result = calculate_factorial(user_input)

    print(f"The factorial of {user_input} is: {result}")

if __name__ == "__main__":
    main()
