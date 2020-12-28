class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        s = set(nums)
        return [idx for idx in range(len(nums)+1)[1:] if idx not in s]

A = [1,1]
solu = Solution()#先对类初始化，才能进行调用
temp = solu.findDisappearedNumbers(A)
if (temp == [2]):
    print('right')
else:
    print('wrong')