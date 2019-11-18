#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include <random>
#include <numeric>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/309-zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-q/
		// 有限状态机，三种状态：rest->hold->sold(cooldown)   ->rest->...
		// 其中，rest和hold是稳态
		// 可以得到状态转移方程
		// sold[i] = hold[i-1] + prices[i];
		// hold[i] = max(hold[i-1], rest[i-1]-prices[i])
		// rest[i] = max(rest[i-1], sold[i-1])
		// 最后一天要么是刚售出(sold)，要么是早就售出了(rest)

		int sold = 0, rest = 0, hold = INT_MIN + 10;
		for (auto p : prices) {
			int pre_sold = sold;
			sold = hold + p;
			hold = max(hold, rest - p);
			rest = max(rest, pre_sold);
		}
		return max(rest, sold);
	}
};