#include<string>
using namespace std;
class Solution {
public:
	int cnt;
	int n;
	void countPalindromic(const string& s, int l, int r) {
		while (0 <= l and r <= n - 1) {
			if (s[l] == s[r]) ++cnt;
			else break;
			--l;
			++r;
		}
	}

	int countSubstrings(string s) {
		cnt = 0;
		n = s.size();
		for (int i = 0; i < n; ++i) {
			countPalindromic(s, i, i);
		}
		for (int i = 0; i < n - 1; ++i) {
			countPalindromic(s, i, i + 1);
		}
		return cnt;
	}
};