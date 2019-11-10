#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

class Solution {
public:
	vector<vector<int>> g;
	int nr;
	int nc;
	int cnt; // closed Island

	void printMatrix() {
		cout << "  ";
		for (int j = 0; j < nc; j++)
			cout << j;
		cout << endl;
		for (int i = 0; i < nr; i++) {
			cout << i << " ";
			for (int j = 0; j < nc; j++) cout << g[i][j];
			cout << endl;
		}
		cout << endl;
	}

	void dfs(int r, int c, int setto) {
		g[r][c] = setto;
		for (int k = 0; k != 4; k++) {
			int rr = r + dx[k], cc = c + dy[k];
			if (rr > 0 && rr < nr - 1 && cc > 0 && cc < nc - 1 && g[rr][cc] == 0) {
				dfs(rr, cc, setto);
			}
		}
	}

	int closedIsland(vector<vector<int>>& grid) {
		g = grid;
		nr = grid.size();
		nc = grid[0].size();
		cnt = 0;

		// 从四个边缘DFS，将非封闭陆地设为2
		for (int r = 0; r < nr; ++r) {
			if (g[r][0] == 0)
				dfs(r, 0, 2);
			if (g[r][nc - 1] == 0)
				dfs(r, nc - 1, 2);
		}
		for (int c = 0; c < nc; ++c) {
			if (g[0][c] == 0)
				dfs(0, c, 2);
			if (g[nr - 1][c] == 0)
				dfs(nr - 1, c, 2);
		}

		// 遍历数组，DFS陆地，并在每次起点时cnt++
		for (int r = 1; r < nr - 1; ++r)
			for (int c = 1; c < nc - 1; ++c) {
				if (g[r][c] == 0)
				{
					dfs(r, c, 3);
					++cnt;
				}
			}

		return cnt;
	}
};

// ====================== Test Module ====================== //

vector<vector<int>> getCase1()
{
	vector<vector<int>> case1;
	vector<int> tmp;
	tmp = { 1,1,1,1,1,1,1,0 };
	case1.push_back(tmp);
	tmp = { 1,0,0,0,0,1,1,0 };
	case1.push_back(tmp);
	tmp = { 1,0,1,0,1,1,1,0 };
	case1.push_back(tmp);
	tmp = { 1,0,0,0,0,1,0,1 };
	case1.push_back(tmp);
	tmp = { 1,1,1,1,1,1,1,0 };
	case1.push_back(tmp);

	return case1;
}

vector<vector<int>> getCase2()
{
	vector<vector<int>> case1;
	vector<int> tmp;
	tmp = { 0,0,1,1,0,1,0,0,1,0 };
	case1.push_back(tmp);
	tmp = { 1,1,0,1,1,0,1,1,1,0 };
	case1.push_back(tmp);
	tmp = { 1,0,1,1,1,0,0,1,1,0 };
	case1.push_back(tmp);
	tmp = { 0,1,1,0,0,0,0,1,0,1 };
	case1.push_back(tmp);
	tmp = { 0,0,0,0,0,0,1,1,1,0 };
	case1.push_back(tmp);
	tmp = { 0,1,0,1,0,1,0,1,1,1 };
	case1.push_back(tmp);
	tmp = { 1,0,1,0,1,1,0,0,0,1 };
	case1.push_back(tmp);
	tmp = { 1,1,1,1,1,1,0,0,0,0 };
	case1.push_back(tmp);
	tmp = { 1,1,1,0,0,1,0,1,0,1 };
	case1.push_back(tmp);
	tmp = { 1,1,1,0,1,1,0,1,1,0 };
	case1.push_back(tmp);

	return case1;
}


void main()
{
	vector<vector<int>> case1;
	case1 = getCase1();

	vector<vector<int>> case2;
	case2 = getCase2();

	Solution solu;
	cout << (solu.closedIsland(case1) == 2) << endl;
	cout << (solu.closedIsland(case2) == 5) << endl;

}