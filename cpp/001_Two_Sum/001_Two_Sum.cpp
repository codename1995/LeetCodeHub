#include<vector>
#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> m;
		for (int i = 0; i != nums.size(); i++)
		{
			int n = nums[i];
			if (m.find(n) != m.end())
				return { m[n], i };
			else
				m[target - n] = i; // 将target与n的差作为key，将位置i作为value，这样下次找到时就可以通过差找到前一个索引，并直接返回结果
		}
		return { -1,-1 };
	}
};