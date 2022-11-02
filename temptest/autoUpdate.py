import subprocess
import os

# command = "pip list --outdated -i https://pypi.tuna.tsinghua.edu.cn/simple"
command = "pip list --outdated"

print('正在获取需要升级的模块信息，请稍后...')
print('Getting the information of outdated modules, wait a moment...')
print()

outdatelist = subprocess.Popen(command,
                               stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE,
                               shell=True).stdout.readlines()
updatelist = []

#print(outdatelist)
for i in outdatelist:
    i = str(i, encoding='utf-8')
    print(i, end='')
    i = i[:i.find(' ')]
    updatelist.append(i)
    #print('\n', i, len(i))

updatelist = updatelist[2:]
#print(updatelist)

c = 1
total = len(updatelist)
if updatelist:
    for x in updatelist:
        print('\n', c, '/', total, ' upgrading ', x, sep='')
        c += 1
        # tempcmd = "pip install -i https://pypi.tuna.tsinghua.edu.cn/simple --upgrade " + x
        tempcmd = "pip install --upgrade " + x
        os.system(tempcmd)
    print("所有模块都已更新完毕！！")
    print('All modules have been updated.')
else:
    print("没有模块需要更新！！")
    print('All modules is updated.')
print('请按回车键以退出程序。')
print('Press enter key to quit.')
input()