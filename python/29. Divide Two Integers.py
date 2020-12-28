class Solution:
    def divide(self, dividend, divisor):
        positive = (dividend < 0) is (divisor < 0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        res=0
        while dividend>=divisor:
            temp,i = divisor,1
            while dividend>=temp:
                # 这个循环不加，只用外层循环也可以；这个循环主要是为了加速代码，使减数/除数以2的指数增加
                # 这样的话，时间复杂度就不是O(dividend/divisor)而是O[log_2_(dividend/divisor)]?
                dividend -= temp
                res+=i
                i<<=1
                temp<<=1
        if not positive:
            res = -res
        return min(max(-2147483648, res),2147483648)



import time
start = time.clock()


TestCase = 25
divisor = -5
ExpectOutput = -5


solu = Solution()#先对类初始化，才能进行调用
temp = solu.divide(TestCase, divisor)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)