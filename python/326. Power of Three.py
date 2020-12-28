class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n<=0:
            return False
        elif n==1:
            return True
        elif (n%3)!=0:
            return False
        isPower = True
        while n!=1:
            if n%3 == 0:
                n = n / 3
            else:
                isPower = False
                break
        return  isPower


import time
start = time.clock()


TestCase = 1
ExpectOutput = False

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.isPowerOfThree(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)