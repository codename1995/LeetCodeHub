class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if (len(prices) <= 1):
            return 0
        #minPrice = max(prices)
        maxProfit = 0
        for i in range(len(prices))[1:]:

            LastVal = prices[i-1]
            val = prices[i]
            dirt = val-LastVal
            if (dirt<=0):
                pass
            else:
                maxProfit = maxProfit + dirt

        return maxProfit


TestCase = [7,1,5,3,6,4]
ExpectOutput = 7
solu = Solution()#先对类初始化，才能进行调用
temp = solu.maxProfit(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')