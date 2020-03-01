#include<vector>

using namespace std;

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> cnt(105, 0);
		for (auto x : nums) ++cnt[x];
		for (int i = 1; i < 105; ++i) cnt[i] = cnt[i] + cnt[i - 1];
		vector<int> res;
		for (auto x : nums) {
			if (x == 0) res.push_back(0);
			else res.push_back(cnt[x - 1]);
		}
		return res;
	}
};