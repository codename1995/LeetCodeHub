class Solution:
    def myAtoi(self, strings) -> int:
        li = [str(val) for val in range(0, 10)]
        if len(strings) == 0:
            return 0
        str_valid_num = ''
        negative = False
        first_non_space_ch = ''
        first_non_space_idx = 0
        for i, ch in enumerate(strings):
            if ch != ' ':
                first_non_space_ch = ch
                first_non_space_idx = i
                break
        if strings[first_non_space_idx] in ['-', '+']:
            negative = True if strings[first_non_space_idx] == '-' else False
            first_non_space_idx += 1
        for i, ch in enumerate(strings[first_non_space_idx:len(strings) + 1]):
            if ch in li:
                str_valid_num += ch
            else:
                break
        if str_valid_num == '':
            return 0
        ans = int(str_valid_num)
        ans *= -1 if negative else 1
        return max(-2 ** 31, min(ans, 2 ** 31 - 1))


import time
start = time.clock()


a= "   -42"
ExpectOutput = -42


solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.myAtoi(a)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)