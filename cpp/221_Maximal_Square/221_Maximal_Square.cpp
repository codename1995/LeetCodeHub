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
	int maximalSquare(vector<vector<char>>& matrix) {
		int max_len = 0;
		int nr = matrix.size();
		if (!nr) return max_len;
		int nc = matrix[0].size();
		vector<vector<int>> dp = vector<vector<int>>(nr + 1, vector<int>(nc + 1, 0));
		for (int r = 1; r <= nr; ++r) {
			for (int c = 1; c <= nc; ++c) {
				if (matrix[r - 1][c - 1] == '1')
					dp[r][c] = min(min(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1]) + 1;
				else
					dp[r][c] = 0;
				max_len = max(max_len, dp[r][c]);
			}
		}
		return max_len * max_len;

	}
};