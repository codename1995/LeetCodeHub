class Solution:
    def getSquareSum(self, n):
        s = 0 #sum
        while n>0:
            s += pow((n%10),2)
            n = n//10
        return s
    def isHappy(self, n):
        #经过手算当这个数变为一个一位数，并且不为1或7时，它就不可能happy
        while n>=10:
            n = self.getSquareSum(n)
        return n==1 or n==7

import time
start = time.clock()


TestCase = 19
ExpectOutput = True


solu = Solution()#先对类初始化，才能进行调用
temp = solu.isHappy(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)