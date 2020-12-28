class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        def genPath(self, ori, des):
            path = ''

            d_c = int(des[0] - ori[0])
            d_r = int(des[1] - ori[1])

            vertical_first = False
            if ori == [0,5] and d_c>0: # ori = 'z'
                vertical_first = True

            if vertical_first:
                ch = 'D' if d_r > 0 else 'U'
                for i in range(abs(d_r)):
                    path += ch

                ch = 'R' if d_c > 0 else 'L'
                for i in range(abs(d_c)):
                    path += ch
            else:
                ch = 'R' if d_c > 0 else 'L'
                for i in range(abs(d_c)):
                    path += ch

                ch = 'D' if d_r > 0 else 'U'
                for i in range(abs(d_r)):
                    path += ch

            path += '!'

            return path

        def getCoord(self, ch):
            asc = ord(ch)  # ascii code
            net_val = asc - 97  # ascii(a) = 97, net_val(a) = 0
            return [net_val % 5, net_val // 5]

        ans = ''
        ori = [0, 0]
        for ch in target:
            des = getCoord(self, ch)
            path = genPath(self, ori, des)
            # print(path)
            ans += path
            ori = des
        return ans

import time
start = time.clock()

targets = "zb"
ExpectOutput = "DDR!UURRR!!DDD!"

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.alphabetBoardPath(targets)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)