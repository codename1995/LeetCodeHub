import math

class Solution:
    def searchRange(self, nums, target):

        # INPUT:    nums: List[int], target: int
        # OUTPUT:   the position of first target number.
        def leftBound(nums, target):
            # return the number of elements that less than target
            l = 0
            r = len(nums)  # right open interval

            while (l < r):
                m = l + (r - l) // 2
                if (nums[m] == target):
                    r = m  # tighten the right border
                elif (nums[m] < target):
                    l = m + 1
                elif (nums[m] > target):
                    r = m

            # return l
            # Use following code to return -1 when target does NOT exist
            if (l==len(nums)): return -1
            return l if nums[l]==target else -1

        # INPUT:    nums: List[int], target: int
        # OUTPUT:   the position of last target number.
        def rightBound(nums, target):
            # return the number of elements that <= target
            l = 0
            r = len(nums)  # right open interval

            while (l < r):
                m = l + (r - l) // 2
                if (nums[m] == target):
                    l = m + 1  # tighten the left border
                elif (nums[m] < target):
                    l = m + 1
                elif (nums[m] > target):
                    r = m

            # return l - 1  # left -1
            # Use following code to return -1 when target does NOT exist
            if (l==0): return -1
            return l-1 if nums[l-1]==target else -1

        le = leftBound(nums, target)
        ri = rightBound(nums, target)
        return [le, ri]


import time
start = time.clock()
nums = [5,7,7,8,8,10]
target = 8
ExpectOutput = [3, 4]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.searchRange(nums, target)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)
