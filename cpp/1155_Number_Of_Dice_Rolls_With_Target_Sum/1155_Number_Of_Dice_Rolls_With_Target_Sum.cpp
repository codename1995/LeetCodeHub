#include<vector>
#include<iostream>
#include<deque>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
	int numRollsToTarget(int d, int f, int target) {
		// @input d-骰子数量  f-骰子最大点数  target-目标和
		// dp[i][k] 掷了i个骰子，点数为k的方案
		// 由于dp[i][k] 仅与dp[i-1][..]有关，因此，可以简化第一维
		vector<long long> dp(target + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= d; ++i) { // 正在掷第i个骰子
			for (int k = target; k >= 0; --k) {					// 更新和为k的情况
				dp[k] = 0;										// 先置零

				for (int j = 1; j <= f && j <= k; ++j) {		// 统计第i个骰子掷出j时，对和为k的影响
					dp[k] = (dp[k] + dp[k - j]) % MOD;			// 实际上是 dp[k] = sum(dp[k-1], dp[k-2], ... dp[k-j])
				}
			}
		}
		return dp[target];
	}
};

void main()
{
	Solution solu;

	int EA1 = 1;
	cout << "case1:";
	cout << (solu.numRollsToTarget(1, 6, 3) == EA1) << endl;

	int EA2 = 6;
	cout << "case2:";
	cout << (solu.numRollsToTarget(2, 6, 7) == EA2) << endl;
}