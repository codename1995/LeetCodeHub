import math
import collections


class Solution:
    def countPairs(self, deli):
        targetSum = [pow(2, i) for i in range(0, 41)]
        dd = collections.Counter(deli)
        sortedKeys = sorted(dd.keys())

        MOD = 10 ** 9 + 7

        def summod(res, x):
            res = res + x % MOD
            res = res % MOD
            return res

        res = 0
        for key in sortedKeys:
            for tsum in targetSum:
                if key * 2 > tsum:
                    continue
                elif (key * 2 == tsum):
                    res = summod(res, dd[key] * (dd[key] - 1) // 2)
                else:
                    if dd.get(tsum - key, 0):
                        res = summod(res, dd[key] * dd[tsum - key])
        return res


import time
start = time.clock()
nums = [149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234]
ExpectOutput = 12

solu = Solution()  # 先对类初始化，才能进行调用
# temp = solu.removeSubfolders(s)
temp = solu.countPairs(nums)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)