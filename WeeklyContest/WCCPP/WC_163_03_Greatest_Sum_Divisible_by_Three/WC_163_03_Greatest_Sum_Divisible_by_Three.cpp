#include<vector>
#include<iostream>
#include<cstring>
#include<numeric>
#include<queue>

using namespace std;

class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		// @liaozhou_101 的解法
		vector<vector<int>> dp(nums.size() + 1, vector<int>(3, INT_MIN));

		dp[0][0] = 0;
		for (int i = 1; i <= nums.size(); ++i) {
			// dp[i][j] 表示 截止到nums[i-1]，模为j的最大和
			for (int j = 0; j < 3; ++j) {
				// 大神代码
				//dp[i][(j + nums[i - 1]) % 3] = max(dp[i - 1][j] + nums[i - 1], dp[i - 1][(j + nums[i - 1]) % 3]);
				// 简化理解版
				// 在上次余数为j时，此次应该更新余数为x的情况，x的等式如下
				int x = (j + nums[i - 1]) % 3; 
				dp[i][x] = max(dp[i - 1][x], dp[i - 1][j] + nums[i - 1]);
				// dp[i][x] 表示此次更新余数为x
				// dp[i-1][j] 表示选取当前数时，应采用上次余数为j的情况
			}
		}

		return dp.back()[0];
	}
};


void main()
{
	vector<int> case1{ 3,6,5,1,8 };
	Solution solu;
	cout << (solu.maxSumDivThree(case1) == 18) << endl;

	vector<int> case3{ 1,2,3,4,4 };
	cout << (solu.maxSumDivThree(case3) == 12) << endl;

	vector<int> case4{ 2,19,6,16,5,10,7,4,11,6 };
	cout << (solu.maxSumDivThree(case4) == 84) << endl;

	vector<int> case5{ 972,944,817,475,436,623,900,268,25,263,627,799,38,943,968,17,
		813,139,772,333,498,593,567,556,550,40,4,862,915,935,366,253,994,893,47,211,
		332,854,73,694,37,63,789,785,419,129,170,404,854,424,712,784,539,697,478,978,509,76,528,
		65,194,352,986,713,730,223,858,366,71,18,60,8,835,70,349,905,446,593,909,592,95,280,900
		,887,303,245,612,708,7,58,564,577,718,410,512,637,535,432,332,770 };
	cout << (solu.maxSumDivThree(case5) == 49701) << endl;
}