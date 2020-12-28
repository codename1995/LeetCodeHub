class Solution:
    def topKFrequent(self, nums, k):
        unique_nums = set(nums)
        appear_cnt = {}
        for num in nums:
            if num in appear_cnt:
                appear_cnt[num] += 1
            else:
                appear_cnt[num] = 0
        # fre = appear_cnt.values()
        # fre.sort()
        # fre.reverse()
        cnt = [[] for _ in range(max(appear_cnt.values())+1)]
        for num in unique_nums:
            cnt[appear_cnt[num]] += [num]
        ans = []
        while k>0:
            row = cnt.pop()
            if len(row)==0:
                continue
            elif len(row)==1:
                ans += [row[0]]
                k-=1
            else:
                ans += [row.pop()]
                cnt += [row]
                k -= 1
        return ans



import time
start = time.clock()

nums = [1,1,1,2,2,3]
k = 2
ExpectOutput = [1, 2]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.topKFrequent(nums, k)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)