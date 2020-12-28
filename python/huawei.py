import re
class Solution:
    def foo(self, n, strings):

        dic = {}
        for i in range(len(strings)):
            s = strings[i]
            s = s.replace(" ", "")
            print(s)
            # result = re.match(r"^[a-z]+", s, flags=re.I)
            for
            print(result)
            pass




import time
start = time.clock()

n=4
data=['  xx= 2', 'yy = 5', '  zz = xx', 'cd= xx+ yy + zz']
ExpectOutput = 9

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.foo(n, data)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)