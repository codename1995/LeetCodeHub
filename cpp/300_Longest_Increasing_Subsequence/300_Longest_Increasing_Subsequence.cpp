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
	int lengthOfLIS(vector<int>& nums) {
		// 2. DP + BinarySearch
		// O(n logn)
		// It works, but hard to recall it in an interview
		// Specifically, update an array ('tails') which store a increasing subarray
		// Visit all numbers, and
		//	if one number larger than all numbers in 'tails', then append it at last
		//	otherwise, insert it into 'tails' by binary search.
		if (nums.size() == 0) return 0;
		vector<int> tails(1, nums[0]);
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] > tails.back()) tails.push_back(nums[i]);
			else {
				int l = 0, r = tails.size() - 1;
				while (l < r)
				{
					int m = (l + r) >> 1;
					if (tails[m] < nums[i]) l = m + 1;
					else r = m;
				}
				tails[l] = nums[i];
			}
		}
		return tails.size();

		// 1. DP
		// O(n^2)
		if (nums.size() == 0) return 0;
		vector<int> dp(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		int maxx = dp[0];
		for (auto n : dp)
			maxx = max(maxx, n);
		return maxx;
	}
};