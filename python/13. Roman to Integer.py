class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        D = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'N': 1000}

        X = list(str(s))
        n = len(X)
        val = 0
        i = 0
        while i < n:
            if (i + 1) < n and (D[X[i]] < D[X[i+1]]):
                val = val + D[X[i+1]] - D[X[i]]
                i = i + 2
            else:
                val = val + D[X[i]]
                i = i + 1

        return val


TestCase = 'IV'
ExpectOutput = 4

solu = Solution()#先对类初始化，才能进行调用
temp = solu.romanToInt(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')