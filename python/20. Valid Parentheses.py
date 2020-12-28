class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        CharDict = {"(": 1, ")": 19, "[": 2, "]": 18, "{": 3, "}": 17}
        stack = []
        ans = True
        for i, ch in enumerate(s):
            if CharDict[ch] < 10:
                stack += [CharDict[ch]]
            else:
                if stack == [] or CharDict[ch] + stack[-1] != 20:
                    ans = False
                    break
                else:
                    stack.pop()
        if stack != []:
            ans = False
        return ans

import time
start = time.clock()


a= "{[]}"
ExpectOutput = True


solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.isValid(a)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)