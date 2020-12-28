class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """






matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3

ExpectOutput = True

solu = Solution()#先对类初始化，才能进行调用
temp = solu.searchMatrix(matrix, target)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)
