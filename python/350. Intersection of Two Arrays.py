class Solution:
    def intersection(self, nums1, nums2):
        nums1.sort()
        nums2.sort()
        nums = []
        while len(nums1)!=0 and len(nums2)!=0:
            n1 = nums1[0]
            n2 = nums2[0]
            if n1==n2:
                nums += [n1]
                nums1.pop(0)
                nums2.pop(0)
            elif n1>n2:
                nums2.pop(0)
            else:
                nums1.pop(0)
        return nums



nums1 = [1,2,2,1]
nums2 = [2,2]
ExpectOutput = [2,2]

solu = Solution()#先对类初始化，才能进行调用
temp = solu.intersection(nums1,nums2)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)