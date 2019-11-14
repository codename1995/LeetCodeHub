#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int nr = grid.size();
		if (nr == 0) return 0;
		int nc = grid[0].size();

		vector<int> dp(nc + 1, INT_MAX); // 由于dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + grid[r][c]，因此可以用一维数组节约空间
		dp[1] = 0;
		for (int r = 1; r < nr + 1; r++)
		{
			for (int c = 1; c < nc + 1; c++)
			{
				dp[c] = min(dp[c], dp[c - 1]) + grid[r - 1][c - 1];	// dp[r][c] = min(dp[r-1][c], dp[r][c-1])
			}
		}
		return dp.back();

		// 一致的思路，但稍微容易理解一点
		// 另外，由于更详细的分支，减少了 nr+nc 次 min 比较，稍微快了一些
		//int nr = grid.size();
		//if (nr == 0) return 0;
		//int nc = grid[0].size();

		//vector<int> dp(nc + 1, 0);
		//for (int r = 0; r < nr; r++)
		//{
		//	for (int c = 0; c < nc; c++)
		//	{
		//		if (r == 0 && c == 0) dp[c] = 0;	// dp[0][0] = 0
		//		else if (r == 0) dp[c] = dp[c - 1];	// dp[r][c] = dp[r][c-1]
		//		else if (c == 0) dp[c] = dp[c];		// dp[r][c] = dp[r-1][c]
		//		else dp[c] = min(dp[c], dp[c - 1]);	// dp[r][c] = min(dp[r-1][c], dp[r][c-1])

		//		dp[c] += grid[r][c];
		//	}
		//}
		//return dp[nc - 1];
	}
};