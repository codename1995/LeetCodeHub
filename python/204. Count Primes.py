
import math

class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<=2:return 0
        isPrime = [False,False] + [True] * (n-2)
        nums = list(range(0,n)) #num in nums equal to its index
        for num in nums:
            if num<=1:continue
            if not isPrime[num]:continue
            for idx in range(num*2,n,num):
                isPrime[idx]=False
        return isPrime.count(True)

TestCase = 20
ExpectOutput = 8

solu = Solution()#先对类初始化，才能进行调用
temp = solu.countPrimes(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
