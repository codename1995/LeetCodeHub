class Solution:
    def minPathSum(self, grid) -> int:
        n_rows = len(grid)
        n_cols = len(grid[0])
        PathSum = [[0 for _ in range(n_cols)] for _ in range(n_rows)]

        for r in range(0, n_rows):
            for c in range(0, n_cols):
                if r==0 and c==0:
                    PathSum[r][c] = grid[r][c]
                elif r==0:
                    PathSum[r][c] = PathSum[r][c-1] + grid[r][c]
                elif c==0:
                    PathSum[r][c] = PathSum[r-1][c] + grid[r][c]
                else:
                    PathSum[r][c] = min(PathSum[r-1][c], PathSum[r][c-1]) + grid[r][c]

        return PathSum[n_rows-1][n_cols-1]



m = [
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
ExpectOutput = 7

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.minPathSum(m)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)