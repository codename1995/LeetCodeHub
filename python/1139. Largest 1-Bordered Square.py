class Solution:
    def largest1BorderedSquare(self, grid):
        max_border = 0
        max_r = len(grid)
        max_c = len(grid[0])
        for c in range(max_c):
            for r in range(max_r):
                if grid[r][c] == 0 or max_r <= max_border + r or max_c <= max_border + c:
                    continue
                left_top_1 = True
                for dirt in range(max_border, max_r - r + 1):
                    right_bottom_1 = True
                    # judge current square match the rules
                    # rule1: left and top border is 1
                    if r+dirt>=max_r or c+dirt>=max_c:
                        print('override')
                        break
                    if grid[r + dirt][c] != 1 or grid[r][c + dirt] != 1:
                        left_top_1 = False
                        break
                    # rule2: bottom and right border is 1
                    for dw in range(1, dirt):
                        if grid[r + dw][c + dirt] != 1 or grid[r + dirt][c + dw] != 1:
                            right_bottom_1 = False
                            break
                    # rule3: bottom-right corner is 1
                    if left_top_1 and right_bottom_1 and grid[r + dirt][c + dirt] == 1:
                        max_border = dirt + 1
        return max_border ** 2



import time
start = time.clock()

# grid = [[1,1,1,1],[1,0,0,1],[1,0,0,1],[1,1,1,1]] #16
grid = [[1,1,1],[1,1,0],[1,1,1],[0,1,1],[1,1,1]]
# grid = [[0,1],[0,1]]
ExpectOutput = 4

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.largest1BorderedSquare(grid)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)