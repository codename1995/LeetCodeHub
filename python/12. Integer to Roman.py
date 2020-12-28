class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        ans = ''
        strs = ['N', 'CN', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        while num > 0:
            for i,val in enumerate(nums):
                if num>=val:
                    ans += strs[i]
                    num -= val
                    break

        return ans




TestCase = 3
ExpectOutput = 'III'

solu = Solution()#先对类初始化，才能进行调用
temp = solu.intToRoman(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')