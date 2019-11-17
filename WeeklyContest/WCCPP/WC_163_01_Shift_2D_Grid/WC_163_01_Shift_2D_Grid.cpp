#include<vector>

using namespace std;

/*
题目隐含时间复杂度分析

0 <= nr, nc <= 50
0 <=   k    <= 1000

因此

nr*nc*k <= 2.5 * 10e6  << 10e9

因此，一个三重循环完全没问题

*/
class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		int nr = grid.size();
		int nc = grid[0].size();
		while (k--) {
			vector<vector<int>> a = grid;
			for (int r = 0; r < nr; ++r) {
				for (int c = 0; c < nc; ++c) {
					if (r == nr - 1 && c == nc - 1)
						grid[0][0] = a[r][c];
					else if (c == nc - 1)
						grid[r + 1][0] = a[r][c];
					else
						grid[r][c + 1] = a[r][c];
				}
			}
		}
		return grid;
	}
};
