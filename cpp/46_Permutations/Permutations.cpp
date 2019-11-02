#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

class Solution {
public:
	// 可作为全排列问题标准模板，参考@liweiwei1419 的思路
	vector<vector<int>> res; // 记录答案
	vector<bool> used; 
	vector<int> _nums;
	void __dfs(int idx, vector<int> pre)
	{
		if (idx == _nums.size())
		{
			res.push_back(pre);
			return;
		}

		for (int i = 0; i <= _nums.size() - 1; i++) {
			if (!used[i])
			{
				used[i] = true;
				pre.push_back(_nums[i]);

				// 在dfs前后，代码对称
				__dfs(idx + 1, pre);

				pre.pop_back();
				used[i] = false;
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0) return res;

		_nums = nums;
		used = vector<bool>(nums.size(), false);
		vector<int> pre;
		__dfs(0, pre);

		return res;
	}
}; 
