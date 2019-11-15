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
	int coinChange(vector<int>& coins, int amount) {
		// 1. DP Bottom-Up
		sort(coins.begin(), coins.end());
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (auto c : coins) {
				if (i - c >= 0 && dp[i-c] != INT_MAX)
					dp[i] = min(dp[i], dp[i - c] + 1);
			}
		}
		return (dp[amount] == INT_MAX) ? -1 : dp[amount];
	}
};