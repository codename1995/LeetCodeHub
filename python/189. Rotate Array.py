class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        k = k%len(nums)
        if(k<=len(nums)):
            nums.reverse()
            temp = nums[0:k]
            temp.reverse()
            nums[0:k] = temp
            temp = nums[k:]
            temp.reverse()
            nums[k:] = temp

        #Do not return anything on website
        return nums



TestCase = [1,2]
ExpectOutput = [2,1]

solu = Solution()#先对类初始化，才能进行调用
temp = solu.rotate(TestCase,3)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')