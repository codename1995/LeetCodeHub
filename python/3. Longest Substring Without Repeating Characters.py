class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s=="":
            return 0
        n_longest = 1
        i=0
        while i+n_longest<len(s):
            currentstr = s[i:i+n_longest]
            if len(currentstr) > len(set(currentstr)):
                i += 1
                continue
            elif s[i+n_longest] not in currentstr:
                n_longest += 1
            else:
                i += 1

        return n_longest



TestCase = 'bcdbcdwb'
ExpectOutput = 4

solu = Solution()#先对类初始化，才能进行调用
temp = solu.lengthOfLongestSubstring(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')