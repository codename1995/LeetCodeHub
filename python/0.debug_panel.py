import math


class Solution:
    def eatenApples(self, apples, days):
        max_days = len(days)
        for i,d in enumerate(days):
            max_days = max(max_days, i+d)

        d = {} # expire date: remaining apples
        cnt = 0
        for dd in range(max_days):
            if (dd<len(days) and days[dd]>0):
                d[dd+days[dd]-1] = d.get(dd+days[dd]-1, 0) + apples[dd]

            expire_dates = sorted(d)

            for i, exp_date in enumerate(expire_dates):
                if (dd<=exp_date and d[exp_date]>0):
                    d[exp_date] -= 1
                    cnt += 1
                    break

            if dd in d:
                del d[dd]
        return cnt





import time
start = time.clock()
apples = [9,10,1,7,0,2,1,4,1,7,0,11,0,11,0,0,9,11,11,2,0,5,5]
days = [3,19,1,14,0,4,1,8,2,7,0,13,0,13,0,0,2,2,13,1,0,3,7]
# nums = "9438957234785635408"
# k = 23
ExpectOutput = 31

solu = Solution()  # 先对类初始化，才能进行调用
# temp = solu.removeSubfolders(s)
temp = solu.eatenApples(apples,days)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)