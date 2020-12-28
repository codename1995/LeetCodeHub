class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:


import time
start = time.clock()


TestCase = 25
divisor = -5
ExpectOutput = -5


solu = Solution()#先对类初始化，才能进行调用
temp = solu.findOcurrences(TestCase, divisor)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)