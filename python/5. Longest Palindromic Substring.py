class Solution:
    def longestPalindrome(self, s: str) -> str:
        #Expand Around Center
        def expandAroundCenter(s,l,r):
            while l>=0 and r<len(s) and s[l]==s[r]:
                l -= 1
                r += 1
            return r-l-1

        if len(s) == 0:
            return ""
        start = 0
        finish = 0
        for i in range(0,len(s)-1):
            len1 = expandAroundCenter(s,i,i)
            len2 = expandAroundCenter(s,i,i+1)
            length = max(len1,len2)
            if length > finish-start+1:
                start = i - (length-1)//2
                finish = i + length//2
        return s[start:finish+1]





        # #dp
        # n = len(s)
        # if n==0:
        #     return ""
        # bP = [[False for _ in range(n)] for _ in range(n)] #A boolean matrix. bP[i,j] indicates str[i:j] is a a palindrome
        # LongestStr = s[-1]
        # for i in range(n):
        #     bP[i][i] = True
        #     if i>=1 and s[i-1]==s[i]:
        #         bP[i-1][i] = True
        #         LongestStr = s[i-1:i+1]
        # for i in range(n-3,-1,-1):
        #     for j in range(i+2,n):
        #         if bP[i+1][j-1] and s[i]==s[j]:
        #             bP[i][j] = True
        #             if j-i+1 > len(LongestStr):
        #                 LongestStr = s[i:j+1]
        # return LongestStr




import time
start = time.clock()



TestCase = 'dbabd'
ExpectOutput = 'dbabd'

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.longestPalindrome(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)