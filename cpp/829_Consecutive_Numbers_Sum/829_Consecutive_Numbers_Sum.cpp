#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int consecutiveNumbersSum(int N) {
		// 这题需要先看下面这个解法，来自剑指offer，时间复杂度不明确，但至少O(N)
		// 因此，当N=INT_MAX时，需要至少10^10运算，超时了
		// 实际运行中，碰到N=3*10^9就超时了
		// 因此需要考虑数学方法
		//int l = 1, r = 1, cnt = 0;
		//int s = 1;
		//while (l < N / 2 + 1)
		//{
		//	if (s == N)
		//		++cnt;

		//	if (s < N)
		//		s += ++r;
		//	else
		//		s -= l++;
		//}
		//return cnt+1;

		// @Leetcode
		// https://leetcode-cn.com/problems/consecutive-numbers-sum/solution/lian-xu-zheng-shu-qiu-he-by-leetcode/
		// 等差数列求和公式： sum = (2*x+k+1) * k
		// 因此枚举法解方程即可
		// 2N = k(2x + k + 1)
		int ans = 0;
		for (int k = 1; k * k <= 2 * N; ++k)
			if (2 * N % k == 0) {
				int y = 2 * N / k - k - 1; // y == 2x
				if (y % 2 == 0 && y >= 0)
					ans++;
			}
		return ans;
	}
};

void main()
{
	Solution solu;
	int case1 = 15;
	cout << (solu.consecutiveNumbersSum(case1) == 4) << endl;
}