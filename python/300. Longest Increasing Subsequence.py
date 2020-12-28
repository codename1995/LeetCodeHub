class Solution:
    def lengthOfLIS(self, nums):
        if len(nums)==0:
            return 0
        elif len(nums)==1:
            return 1
        max_length = 1
        for start in range(len(nums)):
            if len(nums)-start <= max_length:
                break
            LIS=[nums[start]]
            for num in nums[start+1:]:
                if LIS[-1] < num:
                    LIS += [num]
                elif LIS[-1] > num:
                    if len(LIS) == 1 or len(LIS)>=2 and LIS[-2]<num:
                        LIS[-1] = num
            max_length = max(max_length, len(LIS))
        return max_length



import time
start = time.clock()


matrix = [3,5,6,2,5,4,19,5,6,7,12]
ExpectOutput = 6

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.lengthOfLIS(matrix)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)