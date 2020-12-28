class Solution:
    def convert(self, s, numRows):
        if numRows<len(s):
            return s
        strs = [''] * numRows
        row = 0
        row_res = 1
        n = len(s)
        for i,ch in enumerate(s):
            strs[row]  += ch
            if row == numRows-1:
                row_res = -1
            elif row == 0:
                row_res = +1
            row += row_res

        str_out = []
        for i in range(numRows):
            str_out += list(strs[i])
        return ''.join(str_out)

        # for row in range(numRows):
        #     strs += str[i] for i in range(0,n)




TestCase = "PAYPALISHIRING"
n = 3
ExpectOutput = "PAHNAPLSIIGYIR"

solu = Solution()#先对类初始化，才能进行调用
temp = solu.convert(TestCase,n)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)



