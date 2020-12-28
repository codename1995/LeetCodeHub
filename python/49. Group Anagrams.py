class Solution:
    def groupAnagrams(self, strs):
        if len(strs)<=1:
            return [strs]
        dic = dict()
        for s in strs:
            key = ''.join(sorted(s))
            if key in dic:
                dic[key].append(s)
            else:
                dic[key] = [s]
        return list(dic.values())



import time
start = time.clock()


TestCase = ["eat", "tea", "tan", "ate", "nat", "bat"]
ExpectOutput = [
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

solu = Solution()#先对类初始化，才能进行调用
temp = solu.groupAnagrams(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)