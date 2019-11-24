#include<vector>
#include<iostream>

using namespace std;

const int MOD = 1e9 + 7;
class Solution {
public:
	int numWays(int steps, int arrLen) {
		if (arrLen == 1) return 1;
		vector<long> cur(510, 0);
		cur[0] = 1;
		for (int i = 0; i < steps; ++i) {
			vector<long> prv = cur;
			cur[0] = (prv[0] + prv[1]) % MOD;
			for (int j = 1; j < steps && j < arrLen; ++j) {
				if (j + 1 < arrLen)
					cur[j] = (prv[j - 1] + prv[j] + prv[j + 1]) % MOD;
				else
					cur[j] = (prv[j - 1] + prv[j]) % MOD;
			}
		}
		return cur[0];
	}
};