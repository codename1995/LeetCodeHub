class Solution:
    def setZeroes(self, matrix):
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = [] #rows that should be set to zeros
        cols = [] #cols that should be set to zeros

        r = 0
        c = 0
        while r<len(matrix):
            if c==len(matrix[0]):
                r+=1
                c=0
                continue
            elif matrix[r][c] == 0:
                rows += [r]
                cols += [c]

            c+=1
        rows = set(rows)
        cols = set(cols)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i in rows or j in cols:
                    matrix[i][j] = 0
        return matrix

import time
start = time.clock()


TestCase =[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
ExpectOutput = [
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.setZeroes(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)