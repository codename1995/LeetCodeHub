class Solution:
    dic = {}
    for ch in s:
        if ch in dic:
            dic[ch] += 1
        else:
            dic[ch] = 1
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        def binary_search(nums, target):
            l = 0
            r = len(nums) - 1
            while l <= r:
                m = l + (r - l) // 2
                if nums[m] == target:
                    return True
                else:
                    if nums[m] < target:
                        l = m + 1
                    else:
                        r = m - 1
            return False

        # 矩阵的特点是以[0][0]和对角线上的元素分别作为左上顶点和右下顶点的子矩阵均小于右下顶点
        # 因此检查主对角线能够将搜索范围缩小至第一个大于target的主对角线元素所在的行和列之后的所有行和列
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        m = len(matrix)
        n = len(matrix[0])
        start_row = start_col = 0
        for i in range(max(m, n)):
            if i < min(m, n):
                l = r = i
            else:
                if m > n:
                    l = i
                    r = n - 1
                elif m < n:
                    l = m - 1
                    r = i
            # print([l,r])
            if matrix[l][r] == target:
                return True
            elif matrix[l][r] < target:
                start_row = l + 1 if l + 1 < m else l
                start_col = r + 1 if r + 1 < n else r
            else:
                print(start_row)
                print(start_col)
                break

        for row in range(start_row, m):
            if binary_search(matrix[row][0:], target):
                return True
        for col in range(start_col, n):
            vertical_list = [matrix[i][col] for i in range(m)]
            if binary_search(vertical_list, target):
                return True
        return False


import time
start = time.clock()

nums = [[1,4],[2,5]]
target = 2
ExpectOutput = True

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.searchMatrix(nums, target)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)