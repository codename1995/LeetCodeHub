class Solution:
    def numEquivDominoPairs(self, dominoes):
        sum_v = [sum(a) for a in dominoes]
        # print(sum_v)
        dic = {}
        for dom in dominoes:
            sum_val = sum(dom)
            if sum_val not in dic:
                dic[sum_val] = [1,dom]
            else:
                if dom in dic[sum_val]:
                    dic[sum_val][0] += 1
                else:
                    dom.reverse()
                    if dom in dic[sum_val]:
                        dic[sum_val][0] += 1
                    else:
                        dic[sum_val] += dom
        cnt = 0
        for li in dic.values():
            if li[0]>=2:
                cnt+=1
        return cnt






import time
start = time.clock()

nums = [[1,2,3],[3,2,1],[1,3,4],[1,5,6]]
ExpectOutput = 1

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.numEquivDominoPairs(nums)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)