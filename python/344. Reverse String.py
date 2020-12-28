class Solution:
    def reverseString(self, s) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        n = len(s)
        if n >= 2:
            for i in range(int(n//2)):
                s[n-i-1], s[i] = s[i], s[n-i-1]


        return s




import time
start = time.clock()


s = ["h","e","l","l","o"]
ExpectOutput = ["o","l","l","e","h"]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.reverseString(s)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)