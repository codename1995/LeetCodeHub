class Solution:
    def leastInterval(self, tasks, n):
        dict_frq = {}
        for ch in tasks:
            if ch in dict_frq:
                dict_frq[ch] += 1
            else:
                dict_frq[ch] = 1
        Freq = list(dict_frq.values())
        max_freq = max(Freq)
        n_max_freq_tasks = Freq.count(max_freq)
        return max(len(tasks), (max_freq-1) * (n+1) + n_max_freq_tasks)

import time
start = time.clock()

tasks = ["A","A","A","B","B","B"]
n = 2
ExpectOutput = 8

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.leastInterval(tasks, n)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)