import math
import collections

class Solution:
    def canEat(self, candiesCount, queries):
        n = len(candiesCount)
        s = [0] + candiesCount[:]
        for i in range(0, n):
            s[i+1] = s[i] + candiesCount[i]

        res = []
        for q in queries:
            # compute the boundary of eaten candies
            day = q[1]
            cap = q[2]
            min_s = day+1
            max_s = (day+1)*cap

            # compute the boundary of the favourite type
            min_t = s[q[0]]+1
            max_t = s[q[0]+1]

            res.append(min_s<=max_t and max_s>=min_t)

        return res



import time
start = time.clock()
# Time restriction
# Simple case
nums = [7,4,5,3,8]
queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
ExpectOutput = [True, False, True]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.canEat(nums, queries)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)
