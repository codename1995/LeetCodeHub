class Solution:
    def coinChange(self, coins, amount: int) -> int:
        MAX = float('Inf')
        N = [0] + [MAX for _ in range(amount)]

        for i in range(1,amount+1):
            min_N = MAX
            for coin in coins:
                if i-coin>=0:
                    min_N = min(N[i-coin], min_N)
            N[i] = min_N+1

        if N[-1]==MAX:
            N[-1]=-1

        return N[-1]

    # def coinChange(self, coins, amount: int) -> int:
    #     MAX = float("Inf")
    #     dp = [0] + [MAX] * amount
    #
    #     for i in range(1, amount+1):
    #         min_amount = MAX
    #         for c in coins:
    #             if i-c>=0:
    #                 min_amount = min(dp[i-c], min_amount)
    #             else:
    #                 min_amount = min(MAX, min_amount)
    #
    #         dp[i] = min_amount+1
    #     if dp[amount] == float("Inf"):
    #         return -1
    #     return dp[amount]


import time
start = time.clock()


coins = [1,2, 5]
m = 11
ExpectOutput = 3

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.coinChange(coins, m)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)