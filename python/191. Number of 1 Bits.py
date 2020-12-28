class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        #位操作代码
        bits = 0
        while n:
            n = n&(n-1)
            bits += 1
        return bits


        # 我的代码仅在本地work，在线不work，原因不明
        # weight = 0
        # while n!=0:
        #     weight += n%10
        #     n = n // 10
        # return weight



import time
start = time.clock()


TestCase = 0x00000000000000000000000000001011
ExpectOutput = 3


solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.hammingWeight(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)