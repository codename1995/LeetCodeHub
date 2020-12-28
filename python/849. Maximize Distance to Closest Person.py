class Solution:
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        people = [i for i,val in enumerate(seats) if val == 1]
        prev, future = None, next(people)

        ans = 0
        for i,seat in enumerate(seats):
            if seat:
                prev = i
            else:
                

TestCase = [1,0,0,0,1,0,1]
ExpectOutput = 2

solu = Solution()#先对类初始化，才能进行调用
temp = solu.maxDistToClosest(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')