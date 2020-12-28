class Solution:
    def corpFlightBookings(self, bookings, n):
        a = [0] * n
        for i, j, k in bookings:
            a[i - 1] += k
            if j < n:
                a[j] -= k
        seats = 0
        for i in range(n):
            seats += a[i]
            a[i] = seats
        return a


import time
start = time.clock()

bookings = [[1,2,10],[2,3,20],[2,5,25]]
n = 5
ExpectOutput = [10,55,45,25,25]

solu = Solution()  # 先对类初始化，才能进行调用
temp = solu.corpFlightBookings(bookings, 5)
if (temp == ExpectOutput):
    print('right')
else:
    print('wrong')
    print(temp)

elapsed = (time.clock() - start)
print("Time used:", elapsed)