class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        isThirdSameCh = [0] * len(S)
        if (len(S) < 3): return []
        ch0 = S[0];
        ch1 = S[1]
        for i, ch in enumerate(S):
            if i <= 1: continue
            if ch == ch0 and ch == ch1:
                isThirdSameCh[i] = isThirdSameCh[i - 1] + 1
            ch0,ch1 = ch1,ch
        MaxOcc = max(isThirdSameCh)
        ans = []
        for i, val in enumerate(isThirdSameCh):
            if i<(len(isThirdSameCh)-1):
                val2 = isThirdSameCh[i+1]
            else:
                val2 = 0
            if (val>0 and val2==0):
                b=[i - val-1,i]
                ans.append(b)
        return ans

TestCase =  "abcdddeeeeaabbbcd"
ExpectOutput = [[3,5],[6,9],[12,14]]

solu = Solution()#先对类初始化，才能进行调用
temp = solu.largeGroupPositions(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')