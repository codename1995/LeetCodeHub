#include<vector>
#include<deque>
#include<iostream>

using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		// Leetcode acquire you to provide over three solutions and try not use extra space.
		// Solution 1: Brute-force, Space: O(n), T: O(n+k), where n == nums.size()
		// 24 ms, 71.6%
		deque<int> dq;
		int n = nums.size();
		for (int i = n - 1; i > -1; --i)
		{
			dq.push_front(nums.back());
			nums.pop_back();
		}
		for (int i = 0; i < k; ++i) {
			dq.push_front(dq.back());
			dq.pop_back();
		}
		for (int i = 0; i < n; ++i)
		{
			nums.push_back(dq.front());
			dq.pop_front();
		}

		
		// Solution 2: reverse 3 times
		// 1. Reverse whole array
		// 2. Reverse nums[0..k-1]
		// 3. Reverse nums[k..end]
		// S: O(1)  T: O(n)
		// 20ms, 92.7%
		k %= nums.size();
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k-1);
		reverse(nums, k, nums.size() - 1);
	}
	void reverse(vector<int>& nums, int l, int r)
	{
		int tmp;
		while (l < r)
		{
			tmp = nums[l];
			nums[l] = nums[r];
			nums[r] = tmp;
			++l;
			--r;
		}
	}
};
void main()
{
	Solution solu;

	vector<int> case1{ 1,2 };
	vector<int> EA1{ 1,2 };
	solu.rotate(case1, 0);
	cout << "case1:" << (case1 == EA1) << endl;

	vector<int> case2{ -1,-100,3,99 };
	vector<int> EA2{ 3,99,-1,-100 };
	solu.rotate(case2, 2);
	cout << "case2:" << (case2 == EA2) << endl;
}