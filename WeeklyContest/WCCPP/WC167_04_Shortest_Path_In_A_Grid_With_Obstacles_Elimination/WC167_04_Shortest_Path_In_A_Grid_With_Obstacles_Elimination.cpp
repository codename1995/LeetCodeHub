#include<vector>
#include<queue>
#include<iostream>
#include<tuple>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

class Solution {
public:
	// 参考大神@liaozhou_101解法
	vector<vector<vector<int>>> dp;
	int m, n;
	int shortestPath(vector<vector<int>>& grid, int k) {
		m = grid.size();
		n = grid[0].size();
		dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));

		queue<tuple<int, int, int>> q;
		dp[0][0][0] = 0;

		q.push({ 0, 0, 0 });

		while (!q.empty()) {
			auto [r, c, z] = q.front(); // coordiante, C++20特性，VS编译通不过
			q.pop();
			for (int j = 0; j < 4; ++j) {
				int rr = r + dx[j];
				int cc = c + dy[j];
				if (rr >= 0 && rr < m && cc >= 0 && cc < n)
				{
					int tz = z + grid[rr][cc];
					if (tz <= k && dp[rr][cc][tz] > dp[r][c][z] + 1) {
						q.push({ rr,cc,tz });
						dp[rr][cc][tz] = dp[r][c][z] + 1;
					}
				}
			}
		}
		int res = *min_element(dp[m - 1][n - 1].begin(), dp[m - 1][n - 1].end());
		return res == INT_MAX ? -1 : res;
	}
};

void main() {
	Solution solu;
	vector<vector<int>> case1;
	case1.push_back({ 0,0,0 });
	case1.push_back({ 1,1,0 });
	case1.push_back({ 0,0,0 });
	case1.push_back({ 0,1,1 });
	case1.push_back({ 0,0,0 });

	cout << (solu.shortestPath(case1, 1) == 6) << endl;

}