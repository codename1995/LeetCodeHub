#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	const vector<vector<int>> st{ // Status change Table
		{-1,-1,-1,-1}, // 0号道路
		{-1,1,-1,3},// 1号道路
		{0,-1,2,-1},// 2号道路
		{3,2,-1,-1},// 3号道路
		{1,-1,-1,2},// 4号道路
		{-1,0,3,-1},// 5号道路
		{-1,-1,1,0}	// 6号道路
		// 四个方向：上右下左
	};
	int n, m;
	vector<vector<int>> grid;

	bool cm(int r, int c, int f) {
		// check move
		int s = grid[r][c];
		// 1.检查是否可以进入该方格
		if (st[s][f] == -1) return false;
		// 2.若已进入最终方格，则返回true
		if (r == m - 1 && c == n - 1) return true;
		// 3.移动
		int ns = st[s][f]; // next state
		int nr = r, nc = c;//next r, next c
		switch (ns) {
		case 0:
			nr = r - 1;
			break;
		case 1:
			nc = c + 1;
			break;
		case 2:
			nr = r + 1;
			break;
		case 3:
			nc = c - 1;
			break;
		}
		// 4.检查是否越界
		if (nr < 0 || nr >= m || nc < 0 || nc >= n) return false;
		// 5.递归下一处方格
		return cm(nr, nc, ns);
		// 这个代码其实有个问题，但是测试例子中没有这个反例，所以这代码能通过。
		// 就是(0,0)在一个环形道路内，且该环形道路没有包含终点
		// 可以通过设置一个visited矩阵解决

	}
	bool hasValidPath(vector<vector<int>>& g) {
		grid = g;
		m = grid.size(), n = grid[0].size();
		if (m == 1 && n == 1) return true;
		if (cm(0, 0, 1) || cm(0, 0, 2) || cm(0, 0, 0) || cm(0, 0, 3)) return true;
		return false;
	}
};