class Solution:
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        #For this question, if n is positive, then the key is how many 5 the formula has.

        if n==0:
            return 0
        else:
            return n//5 + self.trailingZeroes(n//5)


import time
start = time.clock()


TestCase = 25
ExpectOutput = 0


solu = Solution()#先对类初始化，才能进行调用
temp = solu.trailingZeroes(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)