from functools import reduce
class Solution:
    def numTilePossibilities(self, tiles):
        def factorial(n):
            return reduce(lambda x, y: x * y, [1] + list(range(1, n + 1)))

        def combinations(n,m):
            if m>n:
                return 1
            a = factorial(n)
            b = factorial(m)*factorial(n-m)
            return a//b

        def conuntTimes(tiles):
            dic = {}
            for ch in tiles:
                if ch in dic:
                    continue
                else:
                    dic[ch] = tiles.count(ch)
            return dic

        n = len(tiles)
        dic = conuntTimes(tiles)
        ans = 1
        for num in range(1,n+1):
            if num==n:
                temp = 1
                for val in dic.values():
                    temp *= combinations(num,val)
            else:

            ans += temp
        return ans



import time
start = time.clock()


TestCase = "AAB"
ExpectOutput = 8


solu = Solution()#先对类初始化，才能进行调用
temp = solu.numTilePossibilities(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)