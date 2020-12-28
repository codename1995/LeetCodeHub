class Solution(object):
    def longestSubsequence(self, arr, difference):
        """
        :type arr: List[int]
        :type difference: int
        :rtype: int
        """
        dic = {}
        maxx = 0;
        for val in arr:
            dic[val] = dic.get(val-difference, 0) + 1
            if maxx<dic[val]:
                maxx = dic[val]

        return maxx



import time
start = time.clock()

nums =  [1,5,7,8,5,3,4,2,1]
ExpectOutput = 4

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.longestSubsequence(nums, -2)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)