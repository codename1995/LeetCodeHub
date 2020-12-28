class Solution:
    def findPeakElement(self, nums):
        for i,val in enumerate(nums):
            f1 = f2 = False # f1: left increase,  f2: right decrease
            if i>0:
                f1 = True if nums[i-1]<val else False
            else:
                f1 = True

            if i<len(nums)-1:
                f2 = True if val>nums[i+1] else False
            else:
                f2 = True

            if f1 and f2:
                return i





import time
start = time.clock()

nums = [1,1,1,2,2,3]
ExpectOutput = 5

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.findPeakElement(nums)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)