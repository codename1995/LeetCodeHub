import math
import collections


class Solution:
    def minimumHammingDistance(self, source, target, allowedSwaps):
        # 参考大佬解法：https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations/solution/python3-bing-cha-ji-ha-xi-biao-by-yim-6-4a03/
        n = len(source)
        parent = {i:i for i in range(n)}

        # 定义并查集寻根算法
        def find(x):
            if x!=parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        # 进行连通
        for x,y in allowedSwaps:
            rootX, rootY = find(x), find(y)
            if rootX!=rootY:
                parent[rootY] = rootX

        # 统计连通结果
        dic = collections.defaultdict(list)
        for i in range(n):
            root = find(i)
            dic[root].append(i)

        res = 0
        for k,v in dic.items():
            a = [source[i] for i in v]
            b = [target[i] for i in v]
            Counter = collections.Counter(b)
            for c in a:
                if Counter[c]:
                    Counter[c] -= 1
                else:
                    res += 1

        return res





import time
start = time.clock()
# Time restriction
# Simple case
source = [1,2,3,4]
target = [2,1,4,5]
allowedSwaps = [[0,1],[2,3]]
ExpectOutput = 1
# nums = [8975,9106,5349,7891,3795,983,3532,3121,9341,6891,5416,6221,1247,5343,7006]
# ExpectOutput = 10

solu = Solution()  # 先对类初始化，才能进行调用
# temp = solu.removeSubfolders(s)
temp = solu.minimumHammingDistance(source, target, allowedSwaps)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)
