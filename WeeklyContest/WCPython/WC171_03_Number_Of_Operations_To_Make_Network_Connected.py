import math


class Solution:
    def makeConnected(self, n, connections):
        m = len(connections)
        if (m < n - 1): return -1

        d = {}
        for i in range(n):
            d[i] = 0

        next_vacant_idx = 1  # 避免序号重复即可
        valid_set = 0
        connections.sort()
        for con in connections:
            [a, b] = con
            if (d[a] == 0 and d[b] == 0):
                d[a] = next_vacant_idx
                d[b] = next_vacant_idx
                next_vacant_idx += 1
                valid_set += 1
            elif (d[a] == 0 or d[b] == 0):
                if (d[a] == 0): d[a] = d[b]
                if (d[b] == 0): d[b] = d[a]
            elif (d[a] != d[b]):
                # 此时，两者所在并查集不相等，且均不为零
                c = max(d[a], d[b])
                e = min(d[a], d[b])
                valid_set -= 1
                for i in range(n):
                    if (d[i] == c): d[i] = e
        cnt = valid_set - 1 # 有效集-1 根连线
        for i in range(n):
            if (d[i] == 0): # 每一个单独结点均需一根连线
                cnt += 1
        return cnt



import time
start = time.clock()

k = 10
nums = [[2,8],[1,6],[6,7],[7,9],[0,6],[0,2],[1,8],[2,6],[6,9],[1,3],[0,4]]
ExpectOutput = True

solu = Solution()  # 先对类初始化，才能进行调用
# temp = solu.removeSubfolders(s)
temp = solu.makeConnected(k, nums)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)