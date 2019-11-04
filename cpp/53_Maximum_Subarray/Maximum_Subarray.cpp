#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		// 1.DP 典型题
		// curr记录以nums[i]结尾的最大子序和
		// maxx保存所有最大子序和中最大的
		// 2.二分法 （不是本题最优解，但是可以用这一题来练习二分法——《算法导论》）
		// ..暂时不想练习，有时间再写吧
		int maxx = nums[0];
		int curr = nums[0];
		for (int i = 1; i <= nums.size() - 1; i++)
		{
			curr = max(curr + nums[i], nums[i]);
			maxx = max(maxx, curr);
		}
		return maxx;
	}
};