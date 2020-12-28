class Solution:
    def firstUniqChar(self, s):
        s_dict = dict()
        for i,ch in enumerate(s):
            s_dict[ch] = i
        for i,ch in enumerate(s):
            if ch in s_dict and i==s_dict[ch]:
                return i
            elif ch in s_dict:
                s_dict.pop(ch)
        return -1



s = "lleetcode"
ExpectOutput = 4

solu = Solution()#先对类初始化，才能进行调用
temp = solu.firstUniqChar(s)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)