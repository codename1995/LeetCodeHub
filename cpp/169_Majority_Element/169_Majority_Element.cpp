#include<vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// Solution 1:
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

		// Solution 2: (Not recommend, cause it's too complicated for an interview)
		// Adapt from PARTITION, find the Median in O(n)
	
	}
};