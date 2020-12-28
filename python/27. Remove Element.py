class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if len(nums)<1:return 0
        i=0
        j=len(nums)-1
        while i<j:
            if nums[i]==val:
                if nums[j]==val:
                    j-=1
                else:
                    nums[j],nums[i]=nums[i],nums[j]
            else:
                i+=1
        if val not in nums:
            return len(nums)
        elif nums.index(val)==0:
            return 0
        else:
            return nums.index(val)

TestCase = [2]
val = 13
ExpectOutput = 0

solu = Solution()#先对类初始化，才能进行调用
temp = solu.removeElement(TestCase,val)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')