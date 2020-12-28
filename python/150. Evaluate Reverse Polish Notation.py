class Solution:
    def evalRPN(self, tokens):
        tokens.reverse()
        int_stack = []
        opreation = ['+','-','*','/']
        while tokens:
            ch = tokens.pop()
            if ch not in opreation:
                # ch is a number
                int_stack.append(int(ch))
            else:
                opt = ch
                num2 = int_stack.pop()
                num1 = int_stack.pop()
                if opt == '+':
                    ans = num1+num2
                elif opt == '-':
                    ans = num1-num2
                elif opt == '*':
                    ans = num1*num2
                elif opt == '/':
                    # if num1*num2<0:
                    #     ans = ceil(num1/num2)
                    # else:
                    #     ans = num1//num2
                    ans = int(num1/num2)
                int_stack.append(ans)
        return int_stack.pop()
                    


import time
start = time.clock()

nums = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
ExpectOutput = 22

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.evalRPN(nums)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)