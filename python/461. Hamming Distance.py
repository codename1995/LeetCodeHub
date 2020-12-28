class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        x = x^y
        y = 0
        while x:
            x = x&(x-1)
            y +=1
        return y


import time
start = time.clock()


a= 1
b=4
ExpectOutput = 2


solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.hammingDistance(a, b)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)