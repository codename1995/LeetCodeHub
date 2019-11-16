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
	int maxProduct(vector<int>& nums) {
		int maxx = INT_MIN;
		int cur_max = 1, cur_min = 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] < 0) {
				int tmp = cur_max;
				cur_max = cur_min;
				cur_min = tmp;
			}

			cur_max = max(nums[i], cur_max * nums[i]);
			cur_min = min(nums[i], cur_min * nums[i]);
			maxx = max(maxx, cur_max);
		}
		return maxx;
	}
};