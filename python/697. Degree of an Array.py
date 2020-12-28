class Solution:
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right, count = {}, {}, {}
        for i, val in enumerate(nums):
            if (val not in left): left[val] = i
            right[val] = i
            count[val] = count.get(val, 0) + 1

        ans = len(nums)  # 赋初值较好的一种方式，即给定最坏情况下的值
        degree = max(count.values())
        for x in count:
            if count[x] == degree:
                ans = min(ans, right[x] - left[x] + 1)
        return ans


TestCase = [1,2,2,3,1]
ExpectOutput = 2

solu = Solution()#先对类初始化，才能进行调用
temp = solu.findShortestSubArray(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')