class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        fst0 = 0
        fst1 = 0
        while (fst1 < len(nums)) &  (fst0 < len(nums)):
            if (nums[fst1] == 0):
                fst1 = fst1 + 1
            elif (nums[fst0] != 0):
                fst0 = fst0 + 1
            elif(fst0<fst1):
                nums[fst1], nums[fst0] = nums[fst0], nums[fst1]
                fst0 = fst0 + 1
                fst1 = fst1 + 1
            else:
                fst1=fst1+1
        return nums


TestCase = [1,0]
ExpectOutput = [1,0]
solu = Solution()#先对类初始化，才能进行调用
temp = solu.moveZeroes(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')