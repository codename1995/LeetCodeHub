class Solution:
    n_pathlength = [0]
    def numSquares(self, n: int) -> int:
        # 问题的关键在于如何划分最优子问题
        # 我忽略的一点是，若干个(e.g. k)完全平方数之和，一定是若干-1个(e.g. k-1)完全平方数
        # 加一个完全平方数

        dp = self.n_pathlength
        while len(dp) <= n:
            dp = dp + [min(dp[-i * i] for i in range(1, int(len(dp) ** 0.5 + 1))) + 1,]
        return dp[n]

import time
start = time.clock()


m = 7929
ExpectOutput = 2

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.numSquares(m)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)



elapsed = (time.clock() - start)
print("Time used:",elapsed)