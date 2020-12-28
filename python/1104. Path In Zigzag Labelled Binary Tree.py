class Solution(object):
    def pathInZigZagTree(self, label):
        """
        :type label: int
        :rtype: List[int]
        """
        temp = label
        length = 0
        while temp:
            # ans = [temp] + ans
            temp = temp // 2
            length += 1

        if length % 2 == 1:
            i = length-1
            temp = 2**i + 2**(i+1) - 1 - label
        else:
            temp = label

        ans = []
        while temp:
            ans = [temp] + ans
            temp = temp // 2
            # length += 1

        for i in range(0,length,2):
            ans[i] = 2**i + 2**(i+1) - 1 - ans[i]
        return ans


import time
start = time.clock()

TestCase =  14
ExpectOutput =  [1,3,4,14]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.pathInZigZagTree(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)