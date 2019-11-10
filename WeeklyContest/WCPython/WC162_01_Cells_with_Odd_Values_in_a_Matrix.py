class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        nums = [[0 for _ in range(m)] for _ in range(n)]
        for [row, col] in indices:
            for c in range(m):
                nums[row][c] += 1
            for r in range(n):
                nums[r][col] += 1
        cnt = 0
        for r in range(n):
            for c in range(m):
                if  nums[r][c] % 2 == 1:
                    cnt += 1
        return cnt