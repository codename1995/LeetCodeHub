class Solution:
    def movesToMakeZigzag(self, nums):
        n = len(nums)
        if n == 1:
            return 0
        elif n == 2 and nums[0] != nums[1]:
            return 0
        elif n == 2 and nums[0] == nums[1]:
            return 1
        # condition 1: odd idx number is smaller
        sum1 = 0
        for i in range(1, n, 2):
            if i != n - 1:
                mi = min(nums[i - 1], nums[i + 1])
                sum1 += nums[i] - mi + 1 if nums[i] >= mi else 0
            else:
                sum1 += nums[i] - nums[i - 1] + 1 if nums[i] >= nums[i - 1] else 0
        print(sum1)
        # condition 2: even idx number is smaller
        sum2 = 0
        for i in range(0, n, 2):
            if i == 0:
                sum2 += nums[i] - nums[i + 1] + 1 if nums[i] >= nums[i + 1] else 0
            elif i != n - 1:
                mi = min(nums[i - 1], nums[i + 1])
                sum2 += nums[i] - mi + 1 if nums[i] >= mi else 0
            else:
                sum2 += nums[i] - nums[i - 1] + 1 if nums[i] >= nums[i - 1] else 0

        print(sum2)
        return min(sum1, sum2)

import time
start = time.clock()

nums = [9,6,1,6,2]
ExpectOutput = 4

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.movesToMakeZigzag(nums)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)