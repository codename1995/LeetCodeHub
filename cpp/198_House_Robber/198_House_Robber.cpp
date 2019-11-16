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
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int cur = nums[0], prv1 = nums[0], prv2 = 0;

		for (int i = 1; i < nums.size(); ++i) {
			cur = max(prv1, prv2 + nums[i]);
			prv2 = prv1;
			prv1 = cur;
		}
		return cur;
	}
};