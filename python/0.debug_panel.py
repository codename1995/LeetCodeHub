import math
import collections


class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        res = ""
        n = len(word1)
        m = len(word2)
        i = j = 0

        while (i < n and j < m):
            if word1[i] > word2[j]:
                res += word1[i]
                i += 1
            elif word1[i] < word2[j]:
                res += word2[j]
                j += 1
            else:
                flag_chosen_one = False
                b = 2
                max_b = max(n-i+1, m-j+1)
                while (b<max_b):
                # for b in range(2, max(n - i + 1, m - j + 1)):
                    ii = i + b
                    jj = j + b
                    ii = min(n, ii)
                    jj = min(m, jj)

                    if (ii+10<n and jj+10<m and word1[i:ii]==word2[j:jj]):
                        ii += 10
                        jj += 10
                        b += 10
                        continue

                    if (word1[i:ii] > word2[j:jj]):
                        res += word1[i]
                        i += 1
                        flag_chosen_one = True
                        break
                    elif (word1[i:ii] < word2[j:jj]):
                        res += word2[j]
                        j += 1
                        flag_chosen_one = True
                        break
                    b += 1
                if not flag_chosen_one:
                    res += word1[i]
                    i += 1
        if (i != n):
            res += word1[i:]
        elif (j != m):
            res += word2[j:]

        return res


import time
start = time.clock()
# Time restriction
# Simple case
s1 = "lzxcvnbmqdfqwertyuiopasdfgh"*26 + "a"
s2 = "lzxcvnbmqdfqwertyuiopasdfgh"*26 + "b"
ExpectOutput = "lzxlzxcvncvnbmqdfqwertyuiopbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghlzxcvnbmqdfqwertyuiopasdfghbasdfgha"

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.largestMerge(s1, s2)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)