#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>

using namespace std; 

class Solution {
public:
	int MergeSort(vector<int>& nums, vector<int>& temp, int l, int r)
	{
		if (l == r) return 0;
		int m = (l + r) / 2;
		// 分治
		int res = MergeSort(nums, temp, l, m) + MergeSort(nums, temp, m + 1, r);
		
		// 统计合并后的情况，即left part 和 right part 合起来考虑时多出来的情况
		int tl = l, tr = m + 1;
		while (tl <= m && tr <= r)
		{
			if ((long)nums[tl] > 2 * (long)nums[tr]) // 显示强制转换成long，防止乘以2后溢出
				// 题目只规定nums中的数在int内，没说乘以2后不溢出。
				// 这种坑踩过一次就记住，别再犯了。
			{
				res += m - tl + 1;
				tr++;
			}
			else tl++;
		}

		// 数组合并
		int t_idx=l;
		tl = l;
		tr = m + 1;
		for (int i = l; i <= r; i++)
		{
			if (tl <= m && tr <= r) temp[i] = nums[tl] < nums[tr] ? nums[tl++] : nums[tr++];
			else if (tl <= m)		temp[i] = nums[tl++];
			else					temp[i] = nums[tr++];
		}
		for (int i = l; i <= r; i++)
			nums[i] = temp[i];
		return res;
	}
	int reversePairs(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		vector<int> temp(nums.size());
		return MergeSort(nums, temp, 0, nums.size() - 1);
	}
};


void main()
{
	vector<int> case1{1, 3, 2, 3, 1};
	int EA = 2;

	vector<int> case2{ 2,4,3,5,1 };
	int EA2 = 3;

	Solution solu;
	int AA;

	AA = solu.reversePairs(case1);
	if (EA == AA)
		cout << "case 1:" << true << endl;
	AA = solu.reversePairs(case2);
	if (EA2 == AA)
		cout << "case 2:" << true << endl;

	int a = 0;
}