#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		// @YouLookDeliciousC
		vector<int> res;
		if (matrix.size() == 0) return res;
		int u = 0;
		int d = matrix.size() - 1;
		int l = 0;
		int r = matrix[0].size() - 1;
		while (true)
		{
			for (int i = l; i <= r; i++) res.push_back(matrix[u][i]); // 向右
			if (++u > d) break;
			for (int i = u; i <= d; i++) res.push_back(matrix[i][r]); // 向下
			if (--r < l) break;
			for (int i = r; i >= l; i--) res.push_back(matrix[d][i]); // 向左
			if (--d < u) break;
			for (int i = d; i >= u; i--) res.push_back(matrix[i][l]); // 向上
			if (++l > r) break;
		}
		return res;
	}
};