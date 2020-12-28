class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        water = 0
        for left, h in enumerate(height):
            if h!=0:
                break
        right = left+1
        while right<len(height)-1:
            hr = height(right)
            hl = height(left)
            if hr<hl:
                right += 1
            elif hr>=hl:
                h0 = hl
                left += 1
                while left<right:
                    dh = h0 - height(left)
                    water += dh
                    left += 1

# TestCase = [1,8,6,2,5,4,1,1,1,1,8,3,7]
TestCase = [0,1,0,2,1,0,1,3,2,1,2,1]
ExpectOutput = 6

solu = Solution()#先对类初始化，才能进行调用
temp = solu.trap(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)
