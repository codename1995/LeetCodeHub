class Solution:
    def increasingTriplet(self, nums):
        if len(nums)<=2:
            return False
        first = float("Inf")
        second = float("Inf")
        for num in nums:
            if num<=first:
                first = num
            elif num<=second:
                second = num
            else:
                return True
        return False








import time
start = time.clock()

TestCase = [1,3,2,4,5]
ExpectOutput = True

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.increasingTriplet(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)