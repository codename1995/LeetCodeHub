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
	vector<int> dp;
	vector<int> nums;
	vector<int> squares(int n) {
		vector<int> sq;
		for (int i = 1; i * i <= n; ++i) {
			sq.push_back(i * i);
		}
		return sq;
	}
	int helper(int n) {
		if (dp[n] != INT_MAX) return dp[n];
		for (auto s : nums) {
			if (n == s) dp[n] = 1;
			else if (n - s > 0) dp[n] = min(dp[n], helper(n - s) + 1);
		}
		return dp[n];
	}
	int numSquares(int n) {
		nums = squares(n);
		dp = vector<int>(n + 1, INT_MAX);

		int x = helper(n);
		return helper(n);
	}
};

void main()
{
	Solution solu;
	cout << (solu.numSquares(12) == 3) << endl;
	cout << (solu.numSquares(13) == 2) << endl;
}