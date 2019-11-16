#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include <random>
#include <numeric>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1);
		for (int i = 1; i <= n; ++i) {
			dp[i] = i;
			for (int j = 1; j * j <= i; ++j) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp.back();
	}
};

void main()
{
	Solution solu;
	cout << (solu.numSquares(12) == 3) << endl;
	cout << (solu.numSquares(13) == 2) << endl;
}