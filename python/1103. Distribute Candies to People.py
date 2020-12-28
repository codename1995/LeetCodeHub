class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        ans = [0 for _ in range(num_people)]
        p = 0
        add_candies_last_p = 1
        while candies:
            if add_candies_last_p<=candies:
                ans[p] += add_candies_last_p
                candies -= add_candies_last_p
            else:
                ans[p] = candies
                candies = 0

            p = (p+1)%num_people
            add_candies_last_p += 1
        return ans


import time
start = time.clock()

TestCase =  60
b = 4
ExpectOutput = [15,18,15,12]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.distributeCandies(TestCase, b)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)