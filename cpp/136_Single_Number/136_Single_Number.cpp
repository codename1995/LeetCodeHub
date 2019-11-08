#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int bits = 0;
		for (auto n : nums)
		{
			bits ^= n;
		}
		return bits;

	}
};