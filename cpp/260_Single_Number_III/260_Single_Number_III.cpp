#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int singleNumberCore(vector<int>& nums, int l, int r)
	{
		// copy from solution for 136
		// this function xor every single number in "nums", and return the xor result.
		int bits = 0;
		for (auto n : nums)
			bits ^= n;
		return bits;
	}
	vector<int> singleNumber(vector<int>& nums) {
		// THE SOLUTION IS AWEEEEEEEEEESOME!
		// 1. xor every single number, then we get a special number which is the xor result (denote as X) of the two unique number (A and B)
		// 2. since A and B are not same, X must not be zeros, each bit 1 means A and B are not same on this bit
		//    so, we split the whole array according to the first bit in X
		// 3. now we get two subarray, each of which contains only one unique number while other numbers must appear twice
		// Again, AWEEEESOME!
		int x = singleNumberCore(nums, 0, nums.size() - 1);
		int bit_k = 1;
		while (true)
		{
			if (x & bit_k) break;
			else {
				bit_k = bit_k << 1;
			}
		}
		int a = 0, b = 0;
		for (auto n : nums) {
			if (n & bit_k) a ^= n;
			else b ^= n;
		}
		return { a,b };
	}
};