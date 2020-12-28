class Solution:
    def canJump(self, nums):
        most_left_good = len(nums)-1
        for i in range(len(nums)-2,-1,-1):
            if nums[i]+i>=most_left_good:
                most_left_good = i
        if most_left_good==0:
            return True
        return False



import time
start = time.clock()

TestCase =  [3,2,1,0,4]
ExpectOutput = True

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.canJump(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)