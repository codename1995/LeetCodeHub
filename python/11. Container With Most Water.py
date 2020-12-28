class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = 0
        r = len(height)-1
        MaxArea = 0
        while l<r:
            Area = (r-l) * height[l] if height[l]<height[r] else (r-l) * height[r]
            if MaxArea < Area:
                MaxArea = Area
            if height[l]<height[r]:
                l +=1
            else:
                r -=1

        return MaxArea




# TestCase = [1,8,6,2,5,4,1,1,1,1,8,3,7]
TestCase = [0,0,6,2,5,4,8,3,7]
ExpectOutput = 36

solu = Solution()#先对类初始化，才能进行调用
temp = solu.maxArea(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)