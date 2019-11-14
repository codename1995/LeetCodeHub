#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	// 总结了一下讨论区的思路，比较合理的是两种——最小堆和DP
	// 1.最小堆
	// 由于丑数是2，3，5的倍数，因此不断把它们的倍数压入最小堆中。
	// 可用C++的最小优先队列实现。
	// priority_queue<int, deque<int>, greater<int> > pq; (默认最大优先，因此要写greater
	// 2. DP
	// 一句话的思路：dp[k] = min(dp[idx_2], dp[idx_3], dp[idx_5])
	//     为什么是一个DP问题，因为大于1的丑数一定是2、3、5的积，因此
	// 大于1的丑数可由之前的丑数乘以2，3或5得到，故是DP问题。
	//     最简单的DP问题：dp[k]仅与dp[k-1]有关。而本题dp[k]与dp[a],
	// dp[b],dp[c]三个数有关，其中a,b,c均是需要维护的索引，分别
	// 表示 等待乘2、乘3、乘5 的数的索引。以dp[a]为例，若dp[k]==dp[a]*2，
	// 则这一步之后需要更新a： a++。为了避免可能的重复，此处要用三个
	// if语句而不是if-else，如6=2*3=3*2(dp[idx_2]*3=dp[idx_3]*2)的情况。
	int nthUglyNumber(int n) {
		if (n <= 0) return 0;
		if (n == 1) return 1;
		vector<long> dp{ 1 };
		int p2=0, p3=0, p5=0;
		while (dp.size() != n)
		{
			long curMin = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
			if (curMin == dp[p2] * 2) p2++;
			if (curMin == dp[p3] * 3) p3++;
			if (curMin == dp[p5] * 5) p5++;
			dp.push_back(curMin);
		}
		return dp.back();

	}
};

void main()
{
	Solution solu;
	solu.nthUglyNumber(10); // should be 12
}
