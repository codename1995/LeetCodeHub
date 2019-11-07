#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int lower_bound(vector<int>& nums, int target)
{
	int low = 0, high = nums.size();
	while (low < high)
	{
		int mid = low + (high - low >> 1);
		if (nums[mid] < target)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

int upper_bound(vector<int>& nums, int target)
{
	int low = 0, high = nums.size();
	while (low < high)
	{
		int mid = low + (high - low >> 1);
		if (nums[mid] <= target) //其实就一个等号的区别
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		// 两次二分查找，一次找第一个，一次找最后一个，OVER
		// 翻了一下题解，发现 @hikari解释得很清楚
		// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/shi-yong-lower_bound-he-upper_bound-han-shu-by-ste/
		// C++ algorithm 库中的 lower_bound() 和 upper_bound() 分别返回首个 不小于/大于 target 的迭代器
		
		vector<int> ans = { -1, -1 };
		//查找第一个大于或等于target的元素的迭代器
		auto it_begin = lower_bound(nums.begin(), nums.end(), target);
		//如果找到且等于target
		if (it_begin != nums.end() && *it_begin == target)
			ans[0] = it_begin - nums.begin();
		//查找第一个大于target的元素的迭代器
		auto it_end = upper_bound(nums.begin(), nums.end(), target);
		//当nums只有一个元素时且大于或等于target时，it_end肯定会指向nums.end()
		//                    小于时，nums.begin() == it_end，此时返回-1
		if (it_end != nums.begin() && *(it_end - 1) == target)
			ans[1] = it_end - nums.begin() - 1;
		return ans;



		// My Solution
		//if (nums.size() == 0 || target<nums[0] || target>nums.back())
		//	return { -1, -1 };

		//vector<int> res{ -1,-1 };
		//int l = 0, r = nums.size() - 1;
		//int m;
		//while (l < r)
		//{
		//	m = (l + r) / 2;
		//	if (nums[m] < target)
		//		l = m + 1;
		//	else
		//		r = m;
		//}
		//if (l<nums.size() && nums[l] == target) res[0] = l;
		//else return res;

		//l = 0; r = nums.size() - 1;
		//while (l < r)
		//{
		//	m = (l + r) / 2;
		//	if (nums[m] <= target)
		//		l = m + 1;
		//	else
		//		r = m;
		//}
		//if (l <= nums.size() && nums[l - 1] == target) res[1] = l - 1;

		//return res;
	}
};