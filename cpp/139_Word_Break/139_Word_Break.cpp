#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include <random>
#include <numeric>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		// https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-cban-ben-by-hu-lu-wa-wa-2/
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); ++i) {
			for (auto w : wordDict) {
				int ws = w.size();
				if (i - ws >= 0) {
					if (!s.compare(i - ws, ws, w) && dp[i - ws])
					{
						dp[i] = true;
					}
				}
			}
		}
		return dp.back();
	}
};