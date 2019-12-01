#include<vector> 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int costToPalindrome(const string& s, const int max_l, const int max_r) {
		int cnt = 0;
		if (max_l == max_r) return cnt;
		//if (max_l > max_r || max_l<0 || max_r>s.size() - 1) return false;
		int l = max_l + ((max_r - max_l) >> 1);
		int r = (max_r - max_l) % 2 ? l + 1 : l;
		while (max_l <= l and r <= max_r) {
			if (s[l] != s[r]) ++cnt;
			--l;
			++r;
		}
		return cnt;
	}
	int palindromePartition(string s, int k) {
		int n = s.size();
		vector<vector<int>> min_cost(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				min_cost[i][j] = costToPalindrome(s, i, j);
			}
		}

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX - 1000));
		// dp[i][j] 表示 前i个字符划分出j个回文串的最小代价
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= k && j<=i; ++j) {
				// dp[i][j] = min(dp[i-1][j-1]+c[i-1][i-1], dp[i-2][j-1]+c[i-2][i-1], ... dp[0][j-1]+c[0][i-1])
				// 前i个字符划分j个回文串的最小代价 = 前k个字符划分j-1个字符串 + 第k+1个字符至第i个字符变成回文串的代价
				for (int k = 0; k < i; ++k) {
					dp[i][j] = min(dp[i][j], dp[k][j - 1] + min_cost[k][i - 1]);
				}
			}
		}
		return dp[n][k];

	}
};

void main() {
	Solution solu;

	string case1 = "abc";
	string case2 = "abcdefg";

	cout << (solu.palindromePartition(case2, 4) == 2) << endl;
}
