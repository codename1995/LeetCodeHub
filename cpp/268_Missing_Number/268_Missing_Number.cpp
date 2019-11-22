#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		// XOR
		// T: O(n)
		// S: O(1)
		int n = nums.size();
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res ^= i;
			res ^= nums[i - 1];
		}
		return res;


		// Math
		// T: O(n)
		// S: O(1)
		int n = nums.size();
		int expected_sum = (n + 1) * n / 2;
		int actual_sum = accumulate(nums.begin(), nums.end(), 0);
		return (expected_sum - actual_sum);
	}
};