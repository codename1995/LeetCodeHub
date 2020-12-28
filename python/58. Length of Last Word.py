class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        ls = len(s)
        slow = -1
        while slow>=-ls and s[slow] == ' ':
            slow -= 1
        fast = slow
        while fast >= -ls and s[fast] != ' ':
            fast -= 1
        return slow-fast



TestCase = " s "
ExpectOutput = 1

solu = Solution()#先对类初始化，才能进行调用
temp = solu.lengthOfLastWord(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)