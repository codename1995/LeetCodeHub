#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		// @Leetcode

		int cnt = 0;
		for (long long i = 1; i <= n; i *= 10) {
			long long div = i * 10;
			cnt += (n / div) * i + min(i, max(0LL, n % div - i + 1));
		}
		return cnt;
	}
};