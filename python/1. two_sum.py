# class Solution:
#     def twoSum(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """


class Solution:
    def twoSum(self, nums, target):
        d = {}
        for i,n in enumerate(nums):
            if d.get(target-n, -1) != -1:
                return [d[target-n], i]
            else:
                d[n] = i
        return []


TestCase = [2,7,11,15]
target = 9
ExpectOutput = [0,1]

solu = Solution()#先对类初始化，才能进行调用
temp = solu.twoSum(TestCase,target)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)