class Solution:
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        Nfb = len(flowerbed)
        if Nfb <= (2 * n - 1): return False
        canPlace = [1] * Nfb
        for i, val in enumerate(flowerbed):
            if i != 0 and val == 1: canPlace[i - 1] = 0
            if i != Nfb - 1 and val == 1: canPlace[i + 1] = 0
            if val == 1: canPlace[i] = 0
        for i, val in enumerate(canPlace):
            if i != 0 and canPlace[i - 1] == val == 1:
                canPlace[i] = 0

        if canPlace.count(1) >= n:
            return True
        else:
            return False


TestCase = [1,0,0,0,1]
ExpectOutput = False

solu = Solution()#先对类初始化，才能进行调用
temp = solu.canPlaceFlowers(TestCase,2)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')