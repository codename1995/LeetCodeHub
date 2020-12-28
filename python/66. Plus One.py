class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        up=1
        digits.reverse()
        for i,val in enumerate(digits):
            if up==1 and val==9:
                up=1
                digits[i]=0
                if i==(len(digits)-1):
                    digits.append(1)
            elif up==1:
                digits[i]+=1
                break
        digits.reverse()
        return digits

TestCase = [1,2,3]
ExpectOutput = [1,2,4]

solu = Solution()#先对类初始化，才能进行调用
temp = solu.plusOne(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')