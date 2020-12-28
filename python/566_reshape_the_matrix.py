class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        ExpectedNum = r*c
        ActualNum = 0
        for row in nums:
            ActualNum = ActualNum + len(row)
        if ActualNum!=ExpectedNum:
            return nums
        else:
            vect = []
            for row in nums:
                vect = vect + row
            j=0
            result = [[0 for i in range(c)] for j in range(r)]
            for i in range(r):
                temp = ((i+1)*c)
                result[i][:] = vect[i*c:temp]
            return result

nums = [[1,2,3,4]]
r = 2
c = 2
solu = Solution()#先对类初始化，才能进行调用
temp = solu.matrixReshape(nums, r,c)
if (temp == [[1,2],[3,4]]):
    print('right')
else:
    print('wrong')