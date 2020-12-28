class Solution:
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        sumA = sum(A)
        sumB = sum(B)
        dicA = {}
        avg = (sumA + sumB)/2
        for a in A:
            dicA[avg-sumA+a]=a
        for b in B:
            if(b in dicA):
                return [dicA[b],b]


A = [1,2]
B = [2,3]
solu = Solution()#先对类初始化，才能进行调用
temp = solu.fairCandySwap(A, B)
if (temp == [1,2]):
    print('right')
else:
    print('wrong')