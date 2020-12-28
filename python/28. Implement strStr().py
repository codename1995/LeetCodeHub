class Solution:
    def COMPUTE_PREFIX_FUNCTION(self, P):
        m = len(P)
        pi_array = [0 for _ in range(m+1)]
        k = 0
        for q in range(2,m+1):
            while k>0 and P[k]!=P[q-1]:
                k = pi_array[k]
            if P[k] == P[q-1]:
                k+=1
            pi_array[q] = k
        return pi_array[1:]


    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        S = haystack
        P = needle
        sLen = len(S)
        pLen = len(P)
        i = 0
        j = 0
        pi_array = self.COMPUTE_PREFIX_FUNCTION(P)
        while i<sLen and j<pLen:
            if j==-1 or S[i]==P[j]:
                i += 1
                j += 1
            else:
                j = pi_array[j]-1
                # i = i-1

            if j!=-1:
                print(S[i], P[j])
        if j==pLen:
            return i-j
        else:
            return -1



import time
start = time.clock()

s = "ababaca"
ExpectOutput = [0,0,1,2,3,0,1]
print(Solution().COMPUTE_PREFIX_FUNCTION(s))

str = "mississippi"
pattern = "issip"
ExpectOutput = 4

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.strStr(str, pattern)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)