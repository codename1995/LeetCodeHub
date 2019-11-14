int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
class Solution {
public:
	string w;
	vector<vector<char>> b;
	int nr, nc;

	bool dfs(int r, int c, int cnt) {
		if (r >= 0 && r < nr && c >= 0 && c < nc && cnt < w.size() && b[r][c] == w[cnt]) {
			if (cnt == w.size() - 1) return true;
			else
			{
				bool flag = false;
				char ch = b[r][c];
				b[r][c] = '#';
				for (int i = 0; i != 4; i++) {
					if (dfs(r + dr[i], c + dc[i], cnt + 1))
					{
						// cout<< r << c << endl;
						flag = true;
						break;
					}
				}
				b[r][c] = ch;
				return flag;
			}
		}
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		w = word;
		b = board;
		nr = b.size();
		nc = b[0].size();
		for (int r = 0; r != nr; r++) {
			for (int c = 0; c != nc; c++) {
				if (dfs(r, c, 0)) return true;
			}
		}
		return false;

	}
};