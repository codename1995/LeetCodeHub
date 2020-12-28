#DP, refer to
# https://leetcode.com/problems/maximum-subarray/discuss/20193/DP-solution-and-some-thoughts
class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MaxSumEndAt = [0] * len(nums)
        for i,val in enumerate(nums):
            if i==0:
                MaxSumEndAt[i] = nums[i]
            else:
                MaxSumEndAt[i] = max(val, val+MaxSumEndAt[i-1])
        return max(MaxSumEndAt)

        #Above is a simpler implement.
        # maxSum_EndAt = []
        # for i in range(len(nums)):
        #     maxSum_EndAt += [0]
        #
        # for i,val in enumerate(nums):
        #     if i == 0 :
        #         maxSum_EndAt[i] = val
        #     else:
        #         temp = maxSum_EndAt[i-1] + val
        #         maxSum_EndAt[i] = val if val >= temp else temp
        #
        # S = maxSum_EndAt[0]
        # for s in maxSum_EndAt:
        #     if S < s:
        #         S = s
        # return S





# #Divide and Conque  O(nlgn)
# class Solution:
#     def maxSubArray(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#
#         def CrossArray_maxSubArray(self, nums, l, r):
#             middle = (l + r) // 2
#             maxSum = nums[middle]
#
#             leftMaxSum = maxSum
#             l_subArray = middle
#             for l_sub in range(middle - 1, l - 1, -1):
#                 leftMaxSum += nums[l_sub]
#                 if leftMaxSum > maxSum:
#                     maxSum = leftMaxSum
#                     l_subArray = l_sub
#
#             rightMaxSum = maxSum
#             r_subArray = middle
#             for r_sub in range(middle + 1, r+1):
#                 rightMaxSum += nums[r_sub]
#                 if rightMaxSum > maxSum:
#                     maxSum = rightMaxSum
#                     r_subArray = r_sub
#             return [maxSum, l_subArray, r_subArray]
#
#         def maxSubArray_DivideAndConque(self, nums, l, r):
#             if r == l:
#                 maxSum = nums[l]
#                 return [maxSum, l, r]
#             else:
#                 middle = (r+l)// 2
#                 l_maxSum, l_l, l_r = maxSubArray_DivideAndConque(self, nums, l, middle)
#                 r_maxSum, r_l, r_r = maxSubArray_DivideAndConque(self, nums, middle + 1, r)
#                 m_maxSum, m_l, m_r = CrossArray_maxSubArray(self, nums, l, r)
#
#                 if l_maxSum>=r_maxSum and l_maxSum>=m_maxSum:
#                     return [l_maxSum, l_l, l_r]
#                 elif r_maxSum>=l_maxSum and r_maxSum>=m_maxSum:
#                     return [r_maxSum, r_l, r_r]
#                 else:
#                     return [m_maxSum, m_l, m_r]
#
#         l = 0
#         r = len(nums)-1
#         [maxSum, l, r] = maxSubArray_DivideAndConque(self, nums, l, r)
#         return maxSum






TestCase = [-2,1,-3,4,-1,2,1,-5,4]
# TestCase = [0,-2,0]
ExpectOutput = 0

solu = Solution()#先对类初始化，才能进行调用
temp = solu.maxSubArray(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)