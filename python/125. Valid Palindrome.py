class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.lower()
        s = list(filter(str.isalnum,s))
        i=0
        j=len(s)-1
        flag = True
        while i<j:
            if s[i]!=s[j]:
                flag = False
                break
            else:
                i += 1
                j -=1
        return flag



s = "OP"
ExpectOutput = False

solu = Solution()#先对类初始化，才能进行调用
temp = solu.isPalindrome(s)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)