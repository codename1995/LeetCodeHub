class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x + 1 > pow(2, 31) or x < -pow(2, 31): return 0 #for sake of pseudo overflow
        # num to list
        isnegative = True if x < 0 else False
        x = abs(x)
        nl = []  # num list
        while x != 0:
            nl.append(x % 10)
            x = x // 10
        # remove zeros
        i = 0
        while i < len(nl):
            if nl[i] == 0:
                nl.pop(i)
            else:
                break

        # list to num
        ans = 0
        for val in nl:
            ans = ans * 10 + val
        ans = -ans if isnegative else ans
        if ans + 1 > pow(2, 31) or ans < -pow(2, 31): return 0 #for sake of pseudo overflow
        return ans

TestCase = 123
ExpectOutput = 321

solu = Solution()#先对类初始化，才能进行调用
temp = solu.reverse(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')