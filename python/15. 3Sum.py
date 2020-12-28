class Solution:
    def threeSum(self, nums):
        res = []
        nums.sort()
        for i in range(len(nums)):
            if i>0 and nums[i]==nums[i-1]:
                continue
            elif nums[i]>0:
                break
            l = i+1
            r = len(nums)-1
            while l<r:
                s = nums[i] + nums[l] +nums[r]
                if s>0:
                    r -= 1
                elif s<0:
                    l += 1
                else:
                    res += [[nums[i], nums[l], nums[r]]]
                    while l<r and nums[l]==nums[l+1]:
                        l+=1
                    while l<r and nums[r]==nums[r-1]:
                        r-=1
                    l+=1
                    r-=1
        return res

import time
start = time.clock()


TestCase = [-1, 0, 1, -1, -4]
ExpectOutput = [
  [-1, 0, 1]
]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.threeSum(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)