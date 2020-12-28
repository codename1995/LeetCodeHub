class Solution:
    def numIslands(self, grid):
        def dfs(self, grid, i, j):
            if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] != '1':
                return
            grid[i][j] = '#'
            dfs(self, grid, i - 1, j)
            dfs(self, grid, i + 1, j)
            dfs(self, grid, i, j - 1)
            dfs(self, grid, i, j + 1)

        if not grid:
            return 0

        cnt = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    dfs(self, grid, i, j)
                    cnt += 1

        return cnt


import time
start = time.clock()

TestCase =  [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
ExpectOutput = True

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.numIslands(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)