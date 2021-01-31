import math
import collections

class Solution:
    def restoreArray(self, adjacentPairs):
        n = len(adjacentPairs)
        h = {} # k = value, v = [cnt, adjacent value 1, adjacent value 2]
        for [a,b] in adjacentPairs:
            if h.get(a, [0,0,0])[0] == 0:
                h[a] = [1, b]
            else:
                h[a][0] = 2
                h[a].append(b)

            if h.get(b, [0,0,0])[0] == 0:
                h[b] = [1, a]
            else:
                h[b][0] = 2
                h[b].append(a)

        res = [0] * (n+1)
        for k in h:
            if h[k][0] == 1:
                h[k][0] = -1
                res[0] = k
                break

        for i in range(1, n+1):
            key = res[i-1]
            new_v = h[key][1]
            if h[new_v][0] == -1:
                new_v = h[key][2]

            res[i] = new_v
            h[new_v][0] = -1

        return res



import time
start = time.clock()
# Time restriction
# Simple case
nums = [[4,-2],[1,4],[-3,1]]
ExpectOutput = [-2, 4, 1, -3]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.restoreArray(nums)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)