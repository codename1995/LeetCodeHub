#include<vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// since the majority num (众数) appear more than once
		// it must be the last one that make 'count' ++
		int count = 0;
		int n;
		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0)
				n = nums[i];
			count += (n == nums[i]) ? 1 : -1;
		}
		return n;
	}
};