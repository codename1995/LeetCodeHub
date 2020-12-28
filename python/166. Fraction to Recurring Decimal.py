class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        # no need to consider denominator==0
        res=""
        if numerator/denominator<0:
            res+="-"
        if numerator%denominator==0:
            return str(numerator/denominator)
        numerator=abs(numerator)
        denominator=abs(denominator)
        res+=str(numerator/denominator)
        res+="."
        numerator%=denominator
        i=len(res)
        table={}
        while numerator!=0:
            if numerator not in table.keys():
                table[numerator]=i
            else:
                i=table[numerator]
                res=res[:i]+"("+res[i:]+")"
                return res
            numerator=numerator*10
            res+=str(numerator/denominator)
            numerator%=denominator
            i+=1
        return res


import time
start = time.clock()


a = -25
b = 5
ExpectOutput = 0


solu = Solution()#先对类初始化，才能进行调用
temp = solu.fractionToDecimal(a, b)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)