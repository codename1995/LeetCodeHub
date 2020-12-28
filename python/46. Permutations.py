import copy

class Solution:
    def permute(self, nums):

        ans = []

        def backtrack(comb, nums):
            if len(nums) == 0:
                ans.append(comb)
            else:
                for i in range(len(nums)):
                    # new_nums = copy.deepcopy(nums)
                    # num = new_nums.pop(i)
                    # backtrack(comb + [num], new_nums)

                    if i==0:
                        new_nums = nums[i+1:]
                    elif i==len(nums)-1:
                        new_nums = nums[0:i]
                    else:
                        new_nums = nums[0:i] + nums[i+1:]
                    backtrack(comb+[nums[i]], new_nums)

        if nums:
            backtrack([], nums)
        print(nums)
        return ans


import time
start = time.clock()

nums = [1,2,3]
ExpectOutput = 4

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.permute(nums)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)