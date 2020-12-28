class Solution:
    #DP法
    def uniquePathsWithObstacles(self, obstacleGrid) -> int:
        n_rows = len(obstacleGrid)
        n_cols = len(obstacleGrid[0])
        UPs = [[0]*n_cols for _ in range(n_rows)]
        if obstacleGrid[0][0] == 0:
            UPs[0][0] = 1
        else:
            UPs[0][0] = 0
        for r in range(1,n_rows):
            UPs[r][0] = UPs[r-1][0] if obstacleGrid[r-1][0]==0 and obstacleGrid[r][0]==0 else 0
        for c in range(1,n_cols):
            UPs[0][c] = UPs[0][c-1] if obstacleGrid[0][c-1]==0 and obstacleGrid[0][c]==0 else 0
        for r in range(1,n_rows):
            for c in range(1,n_cols):
                temp1 = UPs[r-1][c] if obstacleGrid[r-1][c]==0 else 0
                temp2 = UPs[r][c-1] if obstacleGrid[r][c-1]==0 else 0
                UPs[r][c] = temp1+temp2 if obstacleGrid[r][c]==0 else 0
        return UPs[-1][-1]

    # #数学算法
    # def uniquePathsWithObstacles(self, obstacleGrid) -> int:
    #     def uniquePaths(self, m: int, n: int) -> int:
    #         def calc_combination(self, m, n):  # 计算组合
    #             def factorial(n):  # 阶乘
    #                 if n == 0:
    #                     return 1
    #                 else:
    #                     return n * factorial(n - 1)
    #
    #             fenzi = factorial(n)
    #             fenmu = factorial(m) * factorial(abs(n - m))
    #             return int(fenzi / fenmu)
    #
    #         return calc_combination(self, m - 1, n + m - 2)
    #     n_rows = len(obstacleGrid)
    #     n_cols = len(obstacleGrid[0])
    #     n_obstacles = 0
    #     for rows in obstacleGrid:
    #         n_obstacles += sum(rows)
    #     if (n_rows <= 1 or n_cols <= 1) and n_obstacles >= 1:
    #         return 0
    #     n_path = [[0 for col in range(n_cols+1)] for row in range(n_rows+1)]
    #     for r in range(1, n_rows+1):
    #         for c in range(1, n_cols+1):
    #             is_obstacle = obstacleGrid[r-1][c-1]
    #             if r==1 and c==1 and is_obstacle==0:
    #                 n_path[r][c] = 1
    #                 continue
    #             if is_obstacle == 0:
    #                 n_path[r][c] = n_path[r-1][c] + n_path[r][c-1]
    #     return n_path[n_rows][n_cols]


m =[[0,0],[1,0]]
ExpectOutput = 2

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.uniquePathsWithObstacles(m)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)