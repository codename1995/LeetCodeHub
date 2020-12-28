class Solution:
    def rotate(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix.reverse()
        n = len(matrix)
        for i in range(n):
            for j in range(i+1,n):
                matrix[i][j],matrix[j][i] = matrix[j][i], matrix[i][j]

        return matrix



TestCase = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]

ExpectOutput = [
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

solu = Solution()#先对类初始化，才能进行调用
temp = solu.rotate(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)