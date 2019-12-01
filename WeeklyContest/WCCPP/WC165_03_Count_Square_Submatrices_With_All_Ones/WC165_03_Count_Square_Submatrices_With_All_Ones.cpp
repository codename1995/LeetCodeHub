#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int nr = matrix.size();
		int nc = matrix[0].size();
		int cnt = accumulate(matrix[0].begin(), matrix[0].end(), 0);
		for (int r = 1; r < nr; ++r) cnt += matrix[r][0];

		for (int r = 1; r < nr; ++r) {
			for (int c = 1; c < nc; ++c) {
				if (matrix[r][c] != 0) {
					matrix[r][c] = min(matrix[r - 1][c - 1], min(matrix[r][c - 1], matrix[r - 1][c])) + 1;
					cnt += matrix[r][c];
				}
			}
		}
		return cnt;
	}
};