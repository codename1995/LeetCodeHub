class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices)==0:
            return 0
        minPrice = prices[0]
        maxProf = 0
        for p in prices:
            if minPrice>p:
                minPrice = p
            elif maxProf<p-minPrice:
                maxProf = p-minPrice

        return maxProf


import time
start = time.clock()


TestCase = [7,6,5,4]
ExpectOutput = 0


solu = Solution()#先对类初始化，才能进行调用
temp = solu.maxProfit(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)