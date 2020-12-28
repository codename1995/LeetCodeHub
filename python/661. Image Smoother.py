class Solution:
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        ans = M.copy()
        for r in range(len(M)):
            for c in range(len(M[0])):
                count=0
                sum=0
                for subr in [r-1,r,r+1]:
                    for subc in [c-1,c,c+1]:
                        if 0<=subr<len(M) and 0<=subc<len(M[0]):
                            sum = sum + M[subr][subc]
                            count = count + 1
                ans[r][c] = int(sum/count)
        return ans

TestCase = [[1,2,3],[4,5,6],[7,8,9],[10,11,12],[13,14,15]]
ExpectOutput = [[3,3,4],[4,5,5],[7,8,8],[10,11,11],[12,12,13]]

solu = Solution()#先对类初始化，才能进行调用
temp = solu.imageSmoother(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')