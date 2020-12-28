class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        s = list(s)
        t = list(t)
        s.sort()
        t.sort()
        if t==s:
            return True
        return False


s = "a"
t = "b"
ExpectOutput = True

solu = Solution()#先对类初始化，才能进行调用
temp = solu.isAnagram(s, t)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)