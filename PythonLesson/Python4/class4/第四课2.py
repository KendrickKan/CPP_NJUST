

while True:
    
    print('\\\\\\\\\\')  
    PM2=int(input('请输入PM2.5: '))
    print(PM2)
    if PM2<35:
        print('优')
    elif PM2<75:
        print('良')
    elif PM2<115:
        print('轻度污染')
    elif PM2<150:
        print('中度污染')
    elif PM2<250:
        print('重度污染')
    else:
        print('严重污染')
                                                                              
