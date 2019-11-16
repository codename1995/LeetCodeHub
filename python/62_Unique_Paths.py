class Solution:
    #DP法
    def uniquePaths(self, m: int, n: int) -> int:
        path = [[0] * n] * m

        for r in range(m):
            for c in range(n):
                if r==0 or c==0:
                    path[r][c] = 1
                else:
                    path[r][c] = path[r-1][c]+path[r][c-1]
        return path[m-1][n-1]


    # #数学算法
    # def uniquePaths(self, m: int, n: int) -> int:
    #     def calc_combination(self, m, n):#计算组合
    #         def factorial(n):#阶乘
    #             if n == 0:
    #                 return 1
    #             else:
    #                 return n * factorial(n - 1)
    #
    #         fenzi = factorial(n)
    #         fenmu = factorial(m)*factorial(abs(n-m))
    #         return int(fenzi/fenmu)
    #
    #     return calc_combination(self, m-1, n+m-2)

m = 7
n = 3
ExpectOutput = 28

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.uniquePaths(m, n)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)