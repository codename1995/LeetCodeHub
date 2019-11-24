#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int countServers(vector<vector<int>>& grid) {
		int nr = grid.size();
		int nc = grid[0].size();

		int cnt = 0; // Total
		vector<int> r_cnt(nr, 0);
		vector<int> c_cnt(nc, 0);
		int single = 0; // Total single server
		for (int r = 0; r < nr; ++r) {
			for (int c = 0; c < nc; ++c) {
				if (grid[r][c] == 1) {
					++r_cnt[r];
					++c_cnt[c];
					++cnt;
				}
			}
		}
		for (int r = 0; r < nr; ++r) {
			for (int c = 0; c < nc; ++c) {
				if (grid[r][c] == 1 && r_cnt[r] == 1 && c_cnt[c] == 1) {
					++single;
				}
			}
		}
		return cnt - single;

	}
};