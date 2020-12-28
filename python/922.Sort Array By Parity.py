class Solution:
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        A.sort(key=lambda x:x%2)
        B = A
        C = B.copy()
        C[0::2] = A[0:(len(A)//2)]
        C[1::2] = A[(len(A)//2):]
        return C

TestCase = [4,2,5,7]
ExpectOutput = [4,5,2,7]
solu = Solution()#先对类初始化，才能进行调用
temp = solu.sortArrayByParityII(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')