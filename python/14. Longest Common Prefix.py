class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        prefix = ""
        if len(strs) == 0: return prefix

        for i in range(len(min(strs))):
            c = strs[0][i]
            if all(str[i] == c for str in strs):
                prefix += c
            else:
                break
        return prefix







TestCase = ["wfloer","flow","flight"]
ExpectOutput = "fl"

solu = Solution()#先对类初始化，才能进行调用
temp = solu.longestCommonPrefix(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')



