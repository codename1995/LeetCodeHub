class Solution:
    def fizzBuzz(self, n: int):
        string = []
        for val in range(1,n+1):
            if (val%3)==0 and (val%5)==0:
                string += ["FizzBuzz"]
            elif (val%3)==0 :
                string += ["Fizz"]
            elif (val%5)==0 :
                string += ["Buzz"]
            else:
                string += [str(val)]
        return string


import time
start = time.clock()


TestCase = 15
ExpectOutput = [
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.fizzBuzz(TestCase)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)