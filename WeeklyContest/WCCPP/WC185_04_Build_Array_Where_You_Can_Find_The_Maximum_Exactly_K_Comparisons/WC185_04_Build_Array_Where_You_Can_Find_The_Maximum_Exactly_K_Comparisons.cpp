#include<vector>

using namespace std;

const int MOD = 1E9 + 7;
class Solution {
public:
	int numOfArrays(int n, int m, int k) {
		if (k == 0) return 0;
		//if (k > m || k > n) return 0;
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
		// dp[length][cur_max_value][cost]
		// dp[h][v][c] = v*dp[h-1][v][c] + dp[h-1][1..v-1][c-1]
		// 上式第一项表示 h-1长度的前缀中，最大值为v，则第h个字符可以取1~v的任一字符
		// 上式第二项表示 h-1长度的前缀中，最大值为1~(v-1)且第h个字符为v
		for (int i = 1; i <= m; ++i) {
			dp[1][i][1] = 1;
		}
		for (int h = 2; h < n + 1; ++h) {
			for (int c = 1; c <= k; ++c) {
				for (int v = 1; v <= m; ++v) {
					long long t = v * (long long)dp[h - 1][v][c] % MOD;
					dp[h][v][c] = t;
					for (int i = 1; i <= v - 1; ++i) {
						dp[h][v][c] = (dp[h][v][c] + dp[h - 1][i][c - 1]) % MOD;
					}
				}
			}
		}
		int s = 0;
		for (int i = 1; i <= m; ++i) {
			s = (s + dp[n][i][k]) % MOD;
		}
		return s;
	}
};

void main()
{
	Solution s;
	int res;
	res = s.numOfArrays(2, 3, 1); // 6
	res = s.numOfArrays(5, 2, 3); // 0
	res = s.numOfArrays(9, 1, 1); // 1

	return;
}