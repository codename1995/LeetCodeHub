#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		// Solution 2: binary search
		// O(n^2)
		int l = 1; // low value
		int h = nums.size() - 1; // high value

		while (l < h) {
			int m = (l + h) >> 1; // middle value
			int cnt_l = 0, cnt_h = 0;
			for (auto num : nums) {
				if (l <= num && num <= m) {
					if (++cnt_l > (m - l+1)) {
						h = m;
						break;
					}
				}
				else if (m < num && num <= h) {
					if (++cnt_h > (h - m)) {
						l = m + 1;
						break;
					}
				}
			}
		}

		return l;

		// Solution 1: sort and check
		// O(nlogn)
		// 由于改变了原数组，因此不符合题目要求
        //sort(nums.begin(), nums.end());
        //for(int i=0;i!=nums.size();i++)
        //{
        //    if(nums[i]<i+1)
        //        return nums[i];
        //}
        //return 0;
    }
};

void main()
{
	Solution solu;

	vector<int> case1{ 1,3,4,2,2 };
	cout << (solu.findDuplicate(case1) == 2) << endl;
}