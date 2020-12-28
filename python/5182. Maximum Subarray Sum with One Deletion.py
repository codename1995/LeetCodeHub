class Solution:
    def maxSubArray(nums):
        """
            1. dp问题. 公式为: dp[i] = max(nums[i], nums[i] + dp[i - 1])
            2. 最大子序和 = 当前元素自身最大, 或者 包含之前后最大
        """
        for i in range(1, len(nums)):
            # nums[i-1]代表dp[i - 1]
            nums[i] = max(nums[i], nums[i] + nums[i - 1])

        return max(nums)



import time
start = time.clock()

nums = [1,-2,0,3]
ExpectOutput = 3

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.maximumSum(nums)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)