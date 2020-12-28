class Solution(object):
    def minHeightShelves(self, books, shelf_width):
        """
        :type books: List[List[int]]
        :type shelf_width: int
        :rtype: int
        """
        n = len(books)
        dp = [float('inf') for _ in range(n + 1)]
        dp[0] = 0

        for i in range(n):
            w = h = 0

            for j in range(i, n):
                w += books[j][0]
                h = max(h, books[j][1])

                if (w <= shelf_width):
                    dp[j + 1] = min(dp[j + 1], dp[i] + h)

        return dp[n]

import time
start = time.clock()

TestCase =  [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]
b = 4
ExpectOutput = 6

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.minHeightShelves(TestCase, b)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)