#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		// @Krahets
		// https://leetcode-cn.com/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/
		// 本题是136 （其他数字出现两次的数组中找到那个仅出现一次的数） 的扩展
		// 136采用异或来解决，本质是 一个数异或自己等于零，即无进位的二进制
		// 因此137题可以采用无进位的三进制来解决
		// ====三进制状态表====
		// 出现次数	0	1	2	3
		// ones		0	1	0	0
		// twos		0	0	1	0
		// threes	0	0	0	1	//进位，本题中可以舍去该变量
		// ====简化的三进制状态表====
		// 出现次数	0	1	2
		// ones		0	1	0	
		// twos		0	0	1
		//// ====某一位出现一个1后，三进制状态更新为====
		//// 出现次数	1	2	3
		//// ones		1	0	0
		//// twos		0	1	0
		int ones = 0;
		int twos = 0;
		for (auto n : nums)
		{
			ones = (ones ^ n) & ~twos; // 可以理解为：n为1时（即多出现一次时），ones要变为1，必须ones本身为0（此时前半个式子（异或）为1），且twos为1
			twos = (twos ^ n) & ~ones; // 可以理解为：n为1时（即多出现一次时），twos要变为1，必须twos本身为0（此时前半个式子（异或）为1），且ones为1
			//// ones的状态更新公式n为1时，ones在出现0次、1次、2次时
			//// 出现次数			1	2	3
			//// ones ^ n			1	0	1
			//// ~twos				1	1	0
			//// (ones ^ n) & ~twos	1	0	0	符合实际		
		}
		return ones;

	}
};

void main()
{
	Solution solu;
	vector<int> case1{ 2,2,2,3 };

	cout << (solu.singleNumber(case1) == 3) << endl;

	int a = 9;
	cout << (a >> 1) << endl;

	cout << (((long)INT_MAX + (long)1) >> 1) << endl;
}